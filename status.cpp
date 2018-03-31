#include <iostream>
#include <fstream>

using namespace std;

int getNumberImages(char type);
int getCameraStatus();

int main() {
    ifstream countFile;
    int numTiffImages = getNumberImages('t');
    int numRawImages = getNumberImages('r');
    int cameraStatus = getCameraStatus();
    cout << numTiffImages << " | " << numRawImages << " | " << cameraStatus << endl;
    return 0;
}

/**
     Gets number of images in directory ./img
     @param type either 't' for tiff or 'r' for raw
     @returns number of images of type tiff or raw
*/
int getNumberImages(char type) {
    int nImages;
    ifstream countFile;
    if (type == 't')
        system("bash countfiles.sh tiff");
    else if (type == 'r')
        system("bash countfiles.sh raw");
    else
        return -1;

    countFile.open("count.txt");
    if (!countFile) {
        return -1;
    }
    countFile >> nImages;
    countFile.close();
    return nImages;
}

int getCameraStatus() {
    return 1;
}
