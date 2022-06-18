#include "../Assets/Gateware/Gateware.h"

#include <fstream>
#include "h2bParser.h"
using namespace H2B;


class Level_Data {

	public:

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
	std::map<std::string,unsigned int> LevelDataMaterials;

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
						//pos = Row.find(",");

						/*std::string element1 = Row.substr(size_t(1), 7);
						std::string element2 = Row.substr(size_t(9), 7);
						std::string element3 = Row.substr(size_t(18), 7);
						std::string element4 = Row.substr(size_t(26), 7);*/

						//int element1 = 0, element2 = 0, element3 = 0, element4 = 0;
						sscanf(Row.c_str(), "(%f,%f,%f,%f)", &(temp.data[(i * 4) + 0]), &(temp.data[(i * 4) + 1]), &(temp.data[(i * 4) + 2]), &(temp.data[(i * 4) + 3]));


					}


					//master_objects.push_back(tempModel);
					//auto iter = LevelDataMaterials.find(objName);


					LEVEL_MODEL_DATA tempData;
					objectNames.push_back(objName);
					tempData.instanceCount = 1;
					tempData.parser.Parse(objName.c_str());

					auto iter = LevelDataMap.find(objName);
					if (iter == LevelDataMap.end())
					{
						for (auto& iter2 : tempData.parser.meshes)
						{
							iter2.drawInfo.indexOffset += masterIndices.size();
						}
						tempData.vertexOffset = masterVertices.size();
						tempData.worldMatrices.push_back(temp);
						LevelDataMap[objName] = tempData;
					}
					else
					{
						LevelDataMap[objName].worldMatrices.push_back(temp);
						++LevelDataMap[objName].instanceCount;
					}

					for (int i = 0; i < tempData.parser.materialCount; i++) {
						H2B::MATERIAL mat = tempData.parser.materials[i];
						auto iter3 = LevelDataMaterials.find(mat.name);
						if (iter3 == LevelDataMaterials.end())
						{//material does not exist
							LevelDataMaterials[tempData.parser.materials[i].name] = masterMaterialCount;
							LevelDataMap[objName].materialId = masterMaterials.size();
							masterMaterials.push_back(tempData.parser.materials[i]);
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

			int iterMeshId = 0;
			for (auto& iter : LevelDataMap)
			{
				iter.second.meshId = iterMeshId;
				iterMeshId += iter.second.worldMatrices.size();
			}

			int hParsed_DEBUG = 0;
			
			std::cout << "No of .h2b files parsed = " << hParsed_DEBUG << "\n";

		}
			return 1;



	}
};