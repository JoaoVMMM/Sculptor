#ifndef SCULPTOR_H
#define SCULPTOR_H

//#include "Voxel.h"

struct Voxel{
    float r,g,b;        // Colors
    float a;            // Transparency
    bool isOn = false;  // Included or not
};

class Sculptor{
    private:
        Voxel ***v;
        int nx, ny, nz;   // Dimension (x,y,z)
        float r, g, b, a; // Color patter
        int i, j, k;


    public:
      Sculptor(int _nx, int _ny, int _nz);
      ~Sculptor();

      void setColor(float r, float g, float b, float alpha);

      void putVoxel(int x, int y, int z);
      void cutVoxel(int x, int y, int z);

      void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
      void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

      void putSphere(int xc, int yc, int zc, int r);
      void cutSphere(int xc, int yc, int zc, int r);

      void putEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz);
      void cutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz);

      void writeOFF(const char* filename);
};


#endif // SCULPTOR_H
