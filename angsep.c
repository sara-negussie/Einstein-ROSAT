#include <stdio.h>
#include <math.h>

double coor_data(float dec1, float dec2, float RA1, float RA2, float *theta, float *d1, float *d2, float *ra1, float *ra2, int *size;){//takes in numbers in degree
    float theta[sizeof(dec1)] = {0}, d1[sizeof(dec1)] = {0}, d2[sizeof(dec1)] = {0}, ra1[sizeof(dec1)] = {0}, ra2[sizeof(dec1)] = {0};
    float del_dec, del_RA, theta_rad, theta_arcsec, val = m.PI/ 180.0;
    int size = 0, i, j, arrayplace = 0;

    printf("Start Program\n");

    for(i = 0; i << sizeof(dec1); i ++){
        j = 0;
        while(j < sizeof(dec1)){
            del_dec = fabs(dec1[i]-dec2[j]);
            del_RA = fabs(RA1[i]-RA2[j]);
            //sin wants numbers in radians but if you send in numbers in degree, it will do it in degree
            if(del_dec < 1 & del_RA * cos(dec1[i]*val) < 1){  //filter
                theta_rad = sin(dec1[i]*val)* sin(dec2[i]*val) + cos(dec1[i]*val)*cos(dec2[i]*val)*cos(del_RA*val) //returns answer in rad
                theta_arcsec = arccos(theta_rad*val) * 206265 //convert from radian to arcsec
                if(theta_arcsec < 300){
                    theta[arrayplace] = theta_arcsec;
                    d1[arrayplace] = dec1[i];
                    d2[arrayplace] = dec2[j];
                    ra1[arrayplace] = RA1[i];
                    ra2[arrayplace] = RA2[j];
                    arrayplace++;
                    size += 1;
                    j += 1;
                }
                else{
                j += 1;
                }
            }
            else{
                j += 1;
            }
        }
    }           
    return *theta, *d1, *d2, *ra1, *ra2, *size;

}


int main(){

    FILE *RA_ROSAT, *RA_Einstein, *DEC_ROSAT, *DEC_Einstein;

    int i;

    RA_ROSAT = fopen("RA_ROSAT.txt","r");
    RA_Einstein = fopen("RA_Einstein.txt","r");
    DEC_ROSAT = fopen("DEC_ROSAT.txt","r");
    DEC_Einstein = fopen("DEC_Einstein.txt","r");

    float RA_R[sizeof(RA_ROSAT)];
    float RA_E[sizeof(RA_Einstein)];
    float DEC_R[sizeof(DEC_ROSAT)];
    float DEC_E[sizeof(DEC_Einstein)];

    for (i = 0; i < sizeof(RA_ROSAT); i++){
        fscanf(RA_ROSAT, "%f", &RA_R[i]);
        fscanf(DEC_ROSAT, "%f", &DEC_R[i]);
    }

    for (i = 0; i < sizeof(RA_Einstein); i++){
        fscanf(RA_Einstein, "%f", &RA_E[i]);
        fscanf(DEC_Einstein, "%f", &DEC_E[i]);
    }


    coor_data(DEC_Einstein, DEC_ROSAT, RA_Einstein, RA_ROSAT, &theta, &dec_E, &dec_R, &RA_E, &RA_R, &size_file)

    //int size_file;
    //float theta, dec_E, dec_R, RA_E, RA_R;
    //theta, dec_E, dec_R, RA_E, RA_R, size_file = coor_data(DEC_Einstein, DEC_ROSAT, RA_Einstein, RA_ROSAT)

    printf("Starting...\n");
}


/*
    printf("End...");
    size(theta);
    ang_sep = zeros(size_file);
    for i in range(size(theta)_
        ang_sep[i] = round(theta[i].value, 1)

    dec_E_new = zeros(size_file)
    for i in range(size(theta)):
        dec_E_new[i] = round(dec_E[i].value, 1)

    dec_R_new = zeros(size_file)
    for i in range(size(theta)):
        dec_R_new[i] = round(dec_R[i].value, 1)

    ra_E_new = zeros(size_file)
    for i in range(size(theta)):
        ra_E_new[i] = round(RA_E[i].value, 1)

    ra_R_new = zeros(size_file)
    for i in range(size(theta)):
        ra_R_new[i] = round(RA_R[i].value, 1)

    print("Writing file")

    with open(r'angular_sep.txt', 'w') as fp:
            for i in range(size(theta)):
                fp.write("Angular Sep = %f\t DEC Einstein = %f\t DEC ROSART = %f\t RA Einstein = %f\t RA ROSART = %f\n" 
                        % ((ang_sep[i]), (dec_E_new[i]), (dec_R_new[i]), (ra_E_new[i]), (ra_R_new[i])))
                
    print("finished")

*/

