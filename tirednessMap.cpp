#include <iostream>
#include <fstream>

int main() {
    std::string file_name;
    std::cin >> file_name;

    std::ifstream input_file;
    input_file.open(file_name);

    int sizeX;
    int sizeY;
    input_file >> sizeX >> sizeY;

    int **tiredness_map = (int**) malloc(sizeY * sizeof(int*));

    for(int i = 0; i < sizeY; i++){
        tiredness_map[i] = (int*) calloc(sizeX, sizeof(int));
    }

    int currentYear, plantingCount;
    int startXCoord, startYCoord;
    int endXCoord, endYCoord;

    while(true){
        int **new_tiredness_map = (int**) malloc(sizeY * sizeof(int*));

        for(int i = 0; i < sizeY; i++){
            new_tiredness_map[i] = (int*) calloc(sizeX, sizeof(int));
        }

        input_file >> currentYear >> plantingCount;
        for(int i = 0; i < plantingCount; i++){
            input_file >> startXCoord >> startYCoord
                       >> endXCoord >> endYCoord;

            for(int y = startYCoord; y <= endYCoord; y++){
                for(int x = startXCoord; x <= endXCoord; x++){
                    new_tiredness_map[y][x]++;
                }
            }
        }


        for(int i=0; i<sizeY; i++){
            for(int j=0; j<sizeX; j++){
                if(new_tiredness_map[i][j] == 1){
                    tiredness_map[i][j]++;
                }
                else if(tiredness_map[i][j] > 0 && new_tiredness_map[i][j] == 0){
                    tiredness_map[i][j]--;
                }
            }
        }

        free(new_tiredness_map);

        if(currentYear == 2017){
            break;
        }
    }

    input_file.close();

    for(int i=0; i<sizeY; i++){
        for(int j=0; j<sizeX; j++){
            std::cout << tiredness_map[i][j] << " ";
        }
        std::cout << "\n";
    }

    free(tiredness_map);

    return 0;
}
