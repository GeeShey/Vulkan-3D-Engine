#include "../Assets/Gateware/Gateware.h"

#include <fstream>
#include "h2bParser.h"
using namespace H2B;


class Level_Data {

private:
	unsigned int masterMeshIdCount = 1;

public:

	//DEBUG VARIABLES
	int DEBUG_FileParsedCount = 0;
	int DEBUG_UniqueMaterialsExtracted = 0;
	int DEBUG_MeshesParsed = 0;
	int DEBUG_SubMeshesParsed = 0;
	int DEBUG_VisibleVertexCount = 0;
	int DEBUG_InstancedMeshes = 0;




	struct LEVEL_MODEL_DATA
	{
		int instanceCount = 1;
		std::vector<GW::MATH::GMATRIXF> worldMatrices;
		H2B::Parser parser;
		unsigned int indexOffset = 0;//UNUSED
		unsigned int vertexOffset = 0;
		int materialId = 0;
		int meshId = 0;
		std::string filepath ="";
	};

	std::vector<std::string> objectNames;
	std::vector<H2B::VERTEX> masterVertices;
	std::vector<H2B::MATERIAL> masterMaterials;

	H2B::MATERIAL defaultMat;

	std::vector<UINT> masterIndices;
	unsigned int masterIndicesCount = 0;
	unsigned int masterMaterialCount = 0;

	std::map<std::string, LEVEL_MODEL_DATA> LevelDataMap;
	std::map<std::string, int> LevelDataMaterials;
	std::map<int, std::string> MaterialTable;

	std::map<int, std::string[3]> TextureList;

	std::string GameLevel_filepath = "";
	Parser p;

	bool getTexturesFromMaterial(H2B::MATERIAL mat,std::vector<std::string>& textures) {

		bool b;
		if (mat.map_Kd || mat.map_Ks || mat.bump) {
			b = true;
			if (mat.map_Kd) {
				std::string temp = std::string(mat.map_Kd);
				std::string tempGamePath = GameLevel_filepath;

				size_t lastindex = (temp.find_last_of("."));
				temp = temp.substr(0, lastindex);
				textures.push_back(tempGamePath.append(temp).append(".ktx"));
			}
			else {
				textures.push_back("../../Assets/Levels/default_diff.ktx");
			}
			if (mat.map_Ns) {
				std::string temp = std::string(mat.map_Ns);
				std::string tempGamePath = GameLevel_filepath;

				size_t lastindex = (temp.find_last_of("."));
				temp = temp.substr(0, lastindex);
				textures.push_back(tempGamePath.append(temp).append(".ktx"));
			}
			else {
				textures.push_back("../../Assets/Levels/default_nrm.ktx");
			}
			if (mat.map_Ks) {
				std::string temp = std::string(mat.map_Ks);
				std::string tempGamePath = GameLevel_filepath;

				size_t lastindex = (temp.find_last_of("."));
				temp = temp.substr(0, lastindex);
				textures.push_back(tempGamePath.append(temp).append(".ktx"));
			}
			else {
				textures.push_back("../../Assets/Levels/default_spec.ktx");
			}
		}
		else {
			for (int j = 0; j < 3; j++) {
				textures.push_back("../../Assets/Levels/default_diff.ktx");
			}
				b = false;
		}
		return b;
	}

	bool isTextured(H2B::MATERIAL mat) {

		if (mat.map_Kd || mat.map_Ks || mat.bump) {
			return true;
			
		}
		else {
			return false;
		}
	}

	int Parse(std:: string _filepath) {
		defaultMat = { 0 };
		masterMaterials.push_back(defaultMat);
		GameLevel_filepath = _filepath;
		int VertOffset = 0;
		int IdxOffset = 0;

		// p.meshes[0].drawInfo.indexOffset = 0;
		std::string GameLevelFileName = GameLevel_filepath;
		GameLevelFileName = GameLevelFileName.append("GameLevel.txt");

		std::ifstream ifs(GameLevelFileName, std::ifstream::in);

		if (ifs.is_open()) {
			std::string line;
			while (std::getline(ifs, line)) {
				GW::MATH::GMATRIXF temp;

				if (std::strcmp(line.c_str(), "MESH") == 0) {

					std::getline(ifs, line);
					std::string objName = line;
					std::string objFilePath = GameLevel_filepath;
					objFilePath = objFilePath.append(line);
					objFilePath = objFilePath.append(".h2b");

					for (int i = 0; i < 4; i++) {
						std::getline(ifs, line);
						std::size_t pos = line.find("(");

						std::string Row = line.substr(pos);
						sscanf(Row.c_str(), "(%f,%f,%f,%f)", &(temp.data[(i * 4) + 0]), &(temp.data[(i * 4) + 1]), &(temp.data[(i * 4) + 2]), &(temp.data[(i * 4) + 3]));


					}

					LEVEL_MODEL_DATA tempData;
					objectNames.push_back(objName);
					tempData.instanceCount = 1;
					bool b = tempData.parser.Parse(objFilePath.c_str());
					if (!b) {
						std::cout << "\n\nUnable to find\\parse file: " << objFilePath <<"\n\n";
						return 0;
					}
					else {
						DEBUG_FileParsedCount++;

					}

					auto iter = LevelDataMap.find(objName);
					DEBUG_MeshesParsed++;
					if (iter == LevelDataMap.end())
					{
						for (auto& iter2 : tempData.parser.meshes)
						{
							iter2.drawInfo.indexOffset += masterIndices.size();
							DEBUG_SubMeshesParsed++;
						}
						tempData.vertexOffset = masterVertices.size();
						tempData.worldMatrices.push_back(temp);
						tempData.filepath = objFilePath;
						LevelDataMap[objName] = tempData;
						
						for (int i = 0; i < LevelDataMap[objName].parser.vertices.size(); i++) {
							masterVertices.push_back(LevelDataMap[objName].parser.vertices[i]);
						}

						for (int i = 0; i < LevelDataMap[objName].parser.indices.size(); i++) {
							masterIndices.push_back(LevelDataMap[objName].parser.indices[i]);
						}

						DEBUG_VisibleVertexCount += LevelDataMap[objName].parser.vertexCount;

					}
					else
					{
						//encountered an instance
						LevelDataMap[objName].worldMatrices.push_back(temp);
						++LevelDataMap[objName].instanceCount;
						DEBUG_InstancedMeshes++ ;
						DEBUG_VisibleVertexCount += LevelDataMap[objName].parser.vertexCount;
						
					}
					for (int i = 0; i < tempData.parser.materialCount; i++) {

						H2B::MATERIAL mat = tempData.parser.materials[i];
						auto iter3 = LevelDataMaterials.find(mat.name);
						if (iter3 == LevelDataMaterials.end())
						{//material does not exist
							int matId = masterMaterials.size();
							if (!isTextured(mat)) {
								matId *= -1;

							}
							LevelDataMaterials[tempData.parser.materials[i].name] = matId;
							LevelDataMap.at(objName).materialId = matId;
							
							
							MaterialTable[masterMaterials.size()] = objName;


							masterMaterials.push_back(mat);
							masterMaterials[masterMaterials.size()-1].map_Kd = strdup(mat.map_Kd);
							masterMaterials[masterMaterials.size()-1].bump = strdup(mat.bump);
							masterMaterials[masterMaterials.size()-1].map_Ks = strdup(mat.map_Ks);
							masterMaterials[masterMaterials.size() - 1].map_Ns = strdup(mat.map_Ns);

							masterMaterials[masterMaterials.size() - 1].name = strdup(mat.name);




							DEBUG_UniqueMaterialsExtracted++;


						}
						else {
							LevelDataMap[objName].materialId = LevelDataMaterials[mat.name];
						}
					}
				}
			}
			ifs.close();

			//int iterMeshId = 0;
			//for (auto& iter : LevelDataMap)
			//{
			//	iter.second.meshId = iterMeshId;
			//	iterMeshId += iter.second.worldMatrices.size();
			//}

			std::cout << "No of .h2b files parsed = " << DEBUG_FileParsedCount << "\n";
			std::cout << "No of unique materials extracted = " << DEBUG_UniqueMaterialsExtracted << "\n";
			std::cout << "No of meshses parsed(exclusing submeshes) = " << DEBUG_MeshesParsed << "\n";
			std::cout << "No of unique submeshes parsed = " << DEBUG_SubMeshesParsed << "\n";
			std::cout << "No of vertices visible in scene = " << DEBUG_VisibleVertexCount << "\n";
			std::cout << "No of vertices uploaded to buffer = " << masterVertices.size() << "\n";
			std::cout << "No of instanced meshes = " << DEBUG_InstancedMeshes << "\n";

			std::cout << "\n\n--------------------\n";
			std::cout << "Instance Report (Original Mesh Draw calls do not count as instances)\n";
			std::cout << "--------------------\n";

			for (auto i : LevelDataMap)
			{
				if (i.second.instanceCount > 1) {
					std::cout << i.first.c_str() << " is being instanced " << i.second.instanceCount -1 << " times\n";
				}
			}

			std::cout << "--------------------\n";
			std::cout << "Instance Report Complete\n";
			std::cout << "--------------------\n";


		}
		else {
			std::cout << "\n\nError Locating Game Level File\n\n";
			return 0;

		}
		

		return 1;



	}
};