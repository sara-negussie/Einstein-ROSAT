#include <stdio.h>
#include <math.h>

int main(){
    
    FILE *RA_ROSAT, *RA_Einstein, *DEC_ROSAT, *DEC_Einstein, *fptr;
    RA_ROSAT = fopen("RA_ROSAT.txt","r");
    RA_Einstein = fopen("RA_Einstein.txt","r");
    DEC_ROSAT = fopen("DEC_ROSAT.txt","r");
    DEC_Einstein = fopen("DEC_Einstein.txt","r");
    printf("Starting...\n");
    float theta[sizeof(RA_ROSAT)] = {0}, DEC_E[sizeof(DEC_Einstein)] = {0}, DEC_R[sizeof(DEC_ROSAT)] = {0}, RA_E[sizeof(RA_Einstein)] = {0}, RA_R[sizeof(RA_ROSAT)] = {0};
    float del_dec, del_RA, theta_rad, theta_arcsec, val = M_PI/ 180.0;
    int size = 0, i, j, arrayplace = 0, num, k, index = sizeof(RA_ROSAT);

    for (i = 0; i < sizeof(RA_ROSAT); i++){
        fscanf(RA_ROSAT, "%f", &RA_R[i]);
        fscanf(DEC_ROSAT, "%f", &DEC_R[i]);
    }

    for (i = 0; i < sizeof(RA_Einstein); i++){
        fscanf(RA_Einstein, "%f", &RA_E[i]);
        fscanf(DEC_Einstein, "%f", &DEC_E[i]);
    }

//double coor_data(float DEC_E, float DEC_R, float RA_E, float RA_R, float *theta, float *DEC_E, float *DEC_R, float *RA_E, float *RA_R, int *size;){
    //takes in numbers in degree
    printf("Start Program\n");

    for(i = 0; i < sizeof(DEC_E); i ++){
        j = 0;
        while(j < sizeof(DEC_R)){
            del_dec = fabs(DEC_E[i]-DEC_R[j]);
            del_RA = fabs(RA_E[i]-RA_R[j]);
            //sin wants numbers in radians but if you send in numbers in degree, it will do it in degree
            if(del_dec < 1 && del_RA * cos(DEC_E[i]*val) < 1){  //filter
                theta_rad = sin(DEC_E[i]*val)* sin(DEC_R[i]*val) + cos(DEC_E[i]*val)*cos(DEC_R[i]*val)*cos(del_RA*val); //returns answer in rad
                theta_arcsec = acos(theta_rad*val) * 206265; //convert from radian to arcsec
                if(theta_arcsec < 300){
                    theta[arrayplace] = theta_arcsec;
                    DEC_E[arrayplace] = DEC_E[i];
                    DEC_R[arrayplace] = DEC_R[j];
                    RA_E[arrayplace] = RA_E[i];
                    RA_R[arrayplace] = RA_R[j];
                    printf("Angular-Sep = %f\t Einstein-Dec = %f\t ROSAT-Dec = %f\t Einstein-RA = %f\t ROSAT-RA = %f\t index = %d\n"
                            ,theta[arrayplace], DEC_E[arrayplace], DEC_R[arrayplace],RA_E[arrayplace],RA_E[arrayplace], arrayplace);
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
    // use appropriate location if you are using MacOS or Linux
    fptr = fopen("theta.txt","w");

    for(k = 0; k < index; k++){
        fprintf(fptr,"Angular-Sep = %f\t Einstein-Dec = %f\t ROSAT-Dec = %f\t Einstein-RA = %f\t ROSAT-RA = %f\n"
        ,theta[index], DEC_E[index], DEC_R[index],RA_E[index],RA_E[index]);     
    }
    
    fclose(fptr);     
}

