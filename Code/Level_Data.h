#include "../Assets/Gateware/Gateware.h"

#include <fstream>
#include "h2bParser.h"
using namespace H2B;


class Level_Data {

private:
	unsigned int masterMeshIdCount = 0;

public:

	//DEBUG VARIABLES
	int DEBUG_FileParsedCount = 0;
	int DEBUG_UniqueMaterialsExtracted = 0;
	int DEBUG_MeshesParsed = 0;
	int DEBUG_SubMeshesParsed = 0;
	int DEBUG_VertexCount = 0;



	struct LEVEL_MODEL_DATA
	{
		int instanceCount = 0;
		std::vector<GW::MATH::GMATRIXF> worldMatrices;
		H2B::Parser parser;
		unsigned int indexOffset = 0;//UNUSED
		unsigned int vertexOffset = 0;
		unsigned int materialId = 0;
		int meshId = 0;
	};

	std::vector<std::string> objectNames;
	std::vector<H2B::VERTEX> masterVertices;
	std::vector<H2B::MATERIAL> masterMaterials;

	std::vector<UINT> masterIndices;
	unsigned int masterIndicesCount = 0;
	unsigned int masterMaterialCount = 0;

	std::map<std::string, LEVEL_MODEL_DATA> LevelDataMap;
	std::map<std::string, unsigned int> LevelDataMaterials;

	std::string GameLevel_filepath = "../../Assets/Levels/";
	Parser p;

	int Parse() {

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
					std::string objName = GameLevel_filepath;
					objName = objName.append(line);
					objName = objName.append(".h2b");

					for (int i = 0; i < 4; i++) {
						std::getline(ifs, line);
						std::size_t pos = line.find("(");

						std::string Row = line.substr(pos);
						sscanf(Row.c_str(), "(%f,%f,%f,%f)", &(temp.data[(i * 4) + 0]), &(temp.data[(i * 4) + 1]), &(temp.data[(i * 4) + 2]), &(temp.data[(i * 4) + 3]));


					}


					//master_objects.push_back(tempModel);
					//auto iter = LevelDataMaterials.find(objName);


					LEVEL_MODEL_DATA tempData;
					objectNames.push_back(objName);
					tempData.instanceCount = 1;
					bool b = tempData.parser.Parse(objName.c_str());
					if (!b) {
						std::cout << "Unable to find\\parse file: " << objName<<"\n";
						std::cout << "You time-travelled and knew your future self would commit this mistake, skipping parse and moving on!\n";
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
						LevelDataMap[objName] = tempData;
						LevelDataMap[objName].meshId = masterMeshIdCount;
						masterMeshIdCount++;
					}
					else
					{
						//encountered an instance
						LevelDataMap[objName].worldMatrices.push_back(temp);
						++LevelDataMap[objName].instanceCount;
						LevelDataMap[objName].meshId = masterMeshIdCount;
						masterMeshIdCount++;
					}

					for (int i = 0; i < tempData.parser.materialCount; i++) {
						H2B::MATERIAL mat = tempData.parser.materials[i];
						auto iter3 = LevelDataMaterials.find(mat.name);
						if (iter3 == LevelDataMaterials.end())
						{//material does not exist
							LevelDataMaterials[tempData.parser.materials[i].name] = masterMaterialCount;
							LevelDataMap[objName].materialId = masterMaterials.size();
							masterMaterials.push_back(tempData.parser.materials[i]);
							DEBUG_UniqueMaterialsExtracted++;
						}
						else {
							LevelDataMap[objName].materialId = LevelDataMaterials[tempData.parser.materials[i].name];
						}

					}


					for (int i = 0; i < LevelDataMap[objName].parser.vertices.size(); i++) {
						masterVertices.push_back(LevelDataMap[objName].parser.vertices[i]);
					}

					for (int i = 0; i < LevelDataMap[objName].parser.indices.size(); i++) {
						masterIndices.push_back(LevelDataMap[objName].parser.indices[i]);
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
			std::cout << "No of vertices in scene = " << masterVertices.size() << "\n";


		}
		else {
			std::cout << "Error Locating Game Level File\n";
			return 0;

		}
		

		return 1;



	}
};