#include "Sculptor.h"
#include <fstream>
#include <cmath>

Sculptor::Sculptor(int _nx, int _ny, int _nz){
        // Constructor
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel **[nx];

    for(i=0; i<nx; i++){
        v[i] = new Voxel *[ny];
        for(j=0; j<ny; j++){
            v[i][j] = new Voxel [nz];
        }
    }
}

Sculptor::~Sculptor(){
        // Destroyer
}

void Sculptor::setColor(float _r, float _g, float _b, float alpha){
    r = _r;
    g = _g;
    b = _b;
    a = alpha;
}

    //  PONTO
void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}
void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

    //  CAIXA
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(i=x0; i<=x1; i++){
        for(j=y0; j<=y1; j++){
            for(k=z0; k<=z1; k++){
                v[i][j][k].isOn = true;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
            }
        }
    }
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(i=x0; i<=x1; i++){
        for(j=y0; j<=y1; j++){
            for(k=z0; k<=z1; k++){
                v[i][j][k].isOn = false;
            }
        }
    }
}

    //  ESFERA
void Sculptor::putSphere(int xc, int yc, int zc, int r){
    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                if(pow(i-xc, 2) + pow(j-yc, 2) + pow(k-zc, 2) <= pow(r, 2)){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}
void Sculptor::cutSphere(int xc, int yc, int zc, int r){
    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                if(pow(i-xc, 2) + pow(j-yc, 2) + pow(k-zc, 2) <= pow(r, 2)){
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}

    //  ELIPSE
void Sculptor::putEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz){
    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                if( ( pow(i-xc, 2) / pow(rx, 2) ) + ( pow(j-yc, 2) / pow(ry, 2) ) + ( pow(k-zc, 2) / pow(rz, 2) ) <= 1){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}
void Sculptor::cutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz){
    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                if( ( pow(i-xc, 2) / pow(rx, 2) ) + ( pow(j-yc, 2) / pow(ry, 2) ) + ( pow(k-zc, 2) / pow(rz, 2) ) <= 1){
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char *filename){
    std::ofstream fout;
    fout.open(filename);
    if(!fout.is_open()){
        exit(1);
    }

    fout << "OFF\n\n";

    int cont=0, sum=0;

    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                if(v[i][j][k].isOn){
                    cont++;
                }
            }
        }
    }

    fout << 8*cont << " " << 6*cont << " 0\n\n";

    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                if(v[i][j][k].isOn){
                    fout << i-0.5 << "  " << j+0.5  << "  " << k-0.5 << "\n";
                    fout << i-0.5 << "  " << j-0.5  << "  " << k-0.5 << "\n";
                    fout << i+0.5 << "  " << j-0.5  << "  " << k-0.5 << "\n";
                    fout << i+0.5 << "  " << j+0.5  << "  " << k-0.5 << "\n";
                    fout << i-0.5 << "  " << j+0.5  << "  " << k+0.5 << "\n";
                    fout << i-0.5 << "  " << j-0.5  << "  " << k+0.5 << "\n";
                    fout << i+0.5 << "  " << j-0.5  << "  " << k+0.5 << "\n";
                    fout << i+0.5 << "  " << j+0.5  << "  " << k+0.5 << "\n\n";
                }
            }
        }
    }

    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                if(v[i][j][k].isOn){
                    fout << 4 << "  " << 0 + sum << "  " << 3 + sum << "  " << 2 + sum << "  " << 1 + sum << "  " << v[i][j][k].r << "  " << v[i][j][k].g << "  " << v[i][j][k].b << "  " << v[i][j][k].a << "\n";
                    fout << 4 << "  " << 4 + sum << "  " << 5 + sum << "  " << 6 + sum << "  " << 7 + sum << "  " << v[i][j][k].r << "  " << v[i][j][k].g << "  " << v[i][j][k].b << "  " << v[i][j][k].a << "\n";
                    fout << 4 << "  " << 0 + sum << "  " << 1 + sum << "  " << 5 + sum << "  " << 4 + sum << "  " << v[i][j][k].r << "  " << v[i][j][k].g << "  " << v[i][j][k].b << "  " << v[i][j][k].a << "\n";
                    fout << 4 << "  " << 0 + sum << "  " << 4 + sum << "  " << 7 + sum << "  " << 3 + sum << "  " << v[i][j][k].r << "  " << v[i][j][k].g << "  " << v[i][j][k].b << "  " << v[i][j][k].a << "\n";
                    fout << 4 << "  " << 3 + sum << "  " << 7 + sum << "  " << 6 + sum << "  " << 2 + sum << "  " << v[i][j][k].r << "  " << v[i][j][k].g << "  " << v[i][j][k].b << "  " << v[i][j][k].a << "\n";
                    fout << 4 << "  " << 1 + sum << "  " << 2 + sum << "  " << 6 + sum << "  " << 5 + sum << "  " << v[i][j][k].r << "  " << v[i][j][k].g << "  " << v[i][j][k].b << "  " << v[i][j][k].a << "\n\n";

                    sum+=8;
                }
            }
        }
    }

    fout.close();
}

