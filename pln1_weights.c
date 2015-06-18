typedef struct PlnWeights pln1_t;

void init_memory_pln1(pln1_t *s) {
    s->clusterCenters = (double**) malloc(sizeof(double*)*3);
    s->clusterCenters[0] = (double*) malloc(sizeof(double)*5);
    s->clusterCenters[1] = (double*) malloc(sizeof(double)*5);
    s->clusterCenters[2] = (double*) malloc(sizeof(double)*5);
    s->R = (double***) malloc(sizeof(double**)*3);
    s->R[0] = (double**) malloc(sizeof(double*)*6);
    s->R[0][0] = (double*) malloc(sizeof(double)*6);
    s->R[0][1] = (double*) malloc(sizeof(double)*6);
    s->R[0][2] = (double*) malloc(sizeof(double)*6);
    s->R[0][3] = (double*) malloc(sizeof(double)*6);
    s->R[0][4] = (double*) malloc(sizeof(double)*6);
    s->R[0][5] = (double*) malloc(sizeof(double)*6);
    s->R[1] = (double**) malloc(sizeof(double*)*6);
    s->R[1][0] = (double*) malloc(sizeof(double)*6);
    s->R[1][1] = (double*) malloc(sizeof(double)*6);
    s->R[1][2] = (double*) malloc(sizeof(double)*6);
    s->R[1][3] = (double*) malloc(sizeof(double)*6);
    s->R[1][4] = (double*) malloc(sizeof(double)*6);
    s->R[1][5] = (double*) malloc(sizeof(double)*6);
    s->R[2] = (double**) malloc(sizeof(double*)*6);
    s->R[2][0] = (double*) malloc(sizeof(double)*6);
    s->R[2][1] = (double*) malloc(sizeof(double)*6);
    s->R[2][2] = (double*) malloc(sizeof(double)*6);
    s->R[2][3] = (double*) malloc(sizeof(double)*6);
    s->R[2][4] = (double*) malloc(sizeof(double)*6);
    s->R[2][5] = (double*) malloc(sizeof(double)*6);
    s->C = (double***) malloc(sizeof(double**)*3);
    s->C[0] = (double**) malloc(sizeof(double*)*2);
    s->C[0][0] = (double*) malloc(sizeof(double)*6);
    s->C[0][1] = (double*) malloc(sizeof(double)*6);
    s->C[1] = (double**) malloc(sizeof(double*)*2);
    s->C[1][0] = (double*) malloc(sizeof(double)*6);
    s->C[1][1] = (double*) malloc(sizeof(double)*6);
    s->C[2] = (double**) malloc(sizeof(double*)*2);
    s->C[2][0] = (double*) malloc(sizeof(double)*6);
    s->C[2][1] = (double*) malloc(sizeof(double)*6);
    s->Et = (double**) malloc(sizeof(double*)*3);
    s->Et[0] = (double*) malloc(sizeof(double)*2);
    s->Et[1] = (double*) malloc(sizeof(double)*2);
    s->Et[2] = (double*) malloc(sizeof(double)*2);
    s->W = (double***) malloc(sizeof(double**)*3);
    s->W[0] = (double**) malloc(sizeof(double*)*2);
    s->W[0][0] = (double*) malloc(sizeof(double)*6);
    s->W[0][1] = (double*) malloc(sizeof(double)*6);
    s->W[1] = (double**) malloc(sizeof(double*)*2);
    s->W[1][0] = (double*) malloc(sizeof(double)*6);
    s->W[1][1] = (double*) malloc(sizeof(double)*6);
    s->W[2] = (double**) malloc(sizeof(double*)*2);
    s->W[2][0] = (double*) malloc(sizeof(double)*6);
    s->W[2][1] = (double*) malloc(sizeof(double)*6);
    s->lambda = (double*) malloc(sizeof(double)*3);
    s->inputMeans = (double*) malloc(sizeof(double)*5);
    s->inputStd = (double*) malloc(sizeof(double)*5);
    s->distanceMeasure = (double*) malloc(sizeof(double)*5);
    s->Nv = (int*) malloc(sizeof(int)*3);
}
void free_memory_pln1(pln1_t *s) {
    free(s->clusterCenters[2]);
    free(s->clusterCenters[1]);
    free(s->clusterCenters[0]);
    free(s->clusterCenters);
    free(s->R[2][5]);
    free(s->R[2][4]);
    free(s->R[2][3]);
    free(s->R[2][2]);
    free(s->R[2][1]);
    free(s->R[2][0]);
    free(s->R[2]);
    free(s->R[1][5]);
    free(s->R[1][4]);
    free(s->R[1][3]);
    free(s->R[1][2]);
    free(s->R[1][1]);
    free(s->R[1][0]);
    free(s->R[1]);
    free(s->R[0][5]);
    free(s->R[0][4]);
    free(s->R[0][3]);
    free(s->R[0][2]);
    free(s->R[0][1]);
    free(s->R[0][0]);
    free(s->R[0]);
    free(s->R);
    free(s->C[2][1]);
    free(s->C[2][0]);
    free(s->C[2]);
    free(s->C[1][1]);
    free(s->C[1][0]);
    free(s->C[1]);
    free(s->C[0][1]);
    free(s->C[0][0]);
    free(s->C[0]);
    free(s->C);
    free(s->Et[2]);
    free(s->Et[1]);
    free(s->Et[0]);
    free(s->Et);
    free(s->W[2][1]);
    free(s->W[2][0]);
    free(s->W[2]);
    free(s->W[1][1]);
    free(s->W[1][0]);
    free(s->W[1]);
    free(s->W[0][1]);
    free(s->W[0][0]);
    free(s->W[0]);
    free(s->W);
    free(s->lambda);
    free(s->inputMeans);
    free(s->inputStd);
    free(s->distanceMeasure);
    free(s->Nv);
}
void load_values_pln1(pln1_t *s) {
    s->clusterCenters[0][0] = 0.730090;
    s->clusterCenters[0][1] = -0.862656;
    s->clusterCenters[0][2] = 0.117559;
    s->clusterCenters[0][3] = 0.412569;
    s->clusterCenters[0][4] = 0.501574;
    s->clusterCenters[1][0] = -0.220777;
    s->clusterCenters[1][1] = 0.176044;
    s->clusterCenters[1][2] = 1.235221;
    s->clusterCenters[1][3] = 0.412569;
    s->clusterCenters[1][4] = 0.501574;
    s->clusterCenters[2][0] = 1.049665;
    s->clusterCenters[2][1] = -0.988057;
    s->clusterCenters[2][2] = -0.946898;
    s->clusterCenters[2][3] = 0.412568;
    s->clusterCenters[2][4] = 0.501574;
    s->R[0][0][0] = 43.000000;
    s->R[0][0][1] = 30.755880;
    s->R[0][0][2] = -40.399720;
    s->R[0][0][3] = 9.272252;
    s->R[0][0][4] = 3.558403;
    s->R[0][0][5] = -9.192543;
    s->R[0][1][0] = 30.755880;
    s->R[0][1][1] = 58.926990;
    s->R[0][1][2] = -44.601840;
    s->R[0][1][3] = 6.914396;
    s->R[0][1][4] = -6.655781;
    s->R[0][1][5] = 6.247785;
    s->R[0][2][0] = -40.399720;
    s->R[0][2][1] = -44.601840;
    s->R[0][2][2] = 61.487150;
    s->R[0][2][3] = -12.039720;
    s->R[0][2][4] = 1.909830;
    s->R[0][2][5] = 9.517821;
    s->R[0][3][0] = 9.272252;
    s->R[0][3][1] = 6.914396;
    s->R[0][3][2] = -12.039720;
    s->R[0][3][3] = 8.593051;
    s->R[0][3][4] = -0.977023;
    s->R[0][3][5] = -7.921045;
    s->R[0][4][0] = 3.558403;
    s->R[0][4][1] = -6.655781;
    s->R[0][4][2] = 1.909830;
    s->R[0][4][3] = -0.977023;
    s->R[0][4][4] = 35.843090;
    s->R[0][4][5] = -6.751182;
    s->R[0][5][0] = -9.192543;
    s->R[0][5][1] = 6.247785;
    s->R[0][5][2] = 9.517821;
    s->R[0][5][3] = -7.921045;
    s->R[0][5][4] = -6.751182;
    s->R[0][5][5] = 58.273560;
    s->R[1][0][0] = 74.000000;
    s->R[1][0][1] = -44.230320;
    s->R[1][0][2] = 46.696450;
    s->R[1][0][3] = 48.645300;
    s->R[1][0][4] = -3.506832;
    s->R[1][0][5] = 15.144860;
    s->R[1][1][0] = -44.230320;
    s->R[1][1][1] = 64.678050;
    s->R[1][1][2] = -60.670490;
    s->R[1][1][3] = -24.766600;
    s->R[1][1][4] = -4.437551;
    s->R[1][1][5] = -13.952000;
    s->R[1][2][0] = 46.696450;
    s->R[1][2][1] = -60.670490;
    s->R[1][2][2] = 68.430360;
    s->R[1][2][3] = 23.182380;
    s->R[1][2][4] = 2.511873;
    s->R[1][2][5] = 21.643680;
    s->R[1][3][0] = 48.645300;
    s->R[1][3][1] = -24.766600;
    s->R[1][3][2] = 23.182380;
    s->R[1][3][3] = 70.651070;
    s->R[1][3][4] = -1.013721;
    s->R[1][3][5] = 6.025793;
    s->R[1][4][0] = -3.506832;
    s->R[1][4][1] = -4.437551;
    s->R[1][4][2] = 2.511873;
    s->R[1][4][3] = -1.013721;
    s->R[1][4][4] = 81.053190;
    s->R[1][4][5] = -2.514304;
    s->R[1][5][0] = 15.144860;
    s->R[1][5][1] = -13.952000;
    s->R[1][5][2] = 21.643680;
    s->R[1][5][3] = 6.025793;
    s->R[1][5][4] = -2.514304;
    s->R[1][5][5] = 45.923800;
    s->R[2][0][0] = 48.000000;
    s->R[2][0][1] = 13.474440;
    s->R[2][0][2] = -6.296738;
    s->R[2][0][3] = -57.917550;
    s->R[2][0][4] = -0.051571;
    s->R[2][0][5] = -5.952314;
    s->R[2][1][0] = 13.474440;
    s->R[2][1][1] = 41.394960;
    s->R[2][1][2] = -33.742550;
    s->R[2][1][3] = -11.024870;
    s->R[2][1][4] = 17.908510;
    s->R[2][1][5] = -12.182690;
    s->R[2][2][0] = -6.296738;
    s->R[2][2][1] = -33.742550;
    s->R[2][2][2] = 35.082490;
    s->R[2][2][3] = 2.520866;
    s->R[2][2][4] = -18.654630;
    s->R[2][2][5] = 5.250093;
    s->R[2][3][0] = -57.917550;
    s->R[2][3][1] = -11.024870;
    s->R[2][3][2] = 2.520866;
    s->R[2][3][3] = 85.755880;
    s->R[2][3][4] = -0.857692;
    s->R[2][3][5] = 3.983605;
    s->R[2][4][0] = -0.051571;
    s->R[2][4][1] = 17.908510;
    s->R[2][4][2] = -18.654630;
    s->R[2][4][3] = -0.857692;
    s->R[2][4][4] = 48.103720;
    s->R[2][4][5] = 0.049670;
    s->R[2][5][0] = -5.952314;
    s->R[2][5][1] = -12.182690;
    s->R[2][5][2] = 5.250093;
    s->R[2][5][3] = 3.983605;
    s->R[2][5][4] = 0.049670;
    s->R[2][5][5] = 60.802650;
    s->C[0][0][0] = 238.000000;
    s->C[0][0][1] = 195.561100;
    s->C[0][0][2] = -221.922200;
    s->C[0][0][3] = 53.979220;
    s->C[0][0][4] = 30.117500;
    s->C[0][0][5] = -65.186720;
    s->C[0][1][0] = 893.000000;
    s->C[0][1][1] = 742.262100;
    s->C[0][1][2] = -850.673100;
    s->C[0][1][3] = 212.444000;
    s->C[0][1][4] = 93.292050;
    s->C[0][1][5] = -147.524400;
    s->C[1][0][0] = 316.000000;
    s->C[1][0][1] = -171.297200;
    s->C[1][0][2] = 183.476600;
    s->C[1][0][3] = 215.642100;
    s->C[1][0][4] = -22.794410;
    s->C[1][0][5] = 58.892690;
    s->C[1][1][0] = 1009.000000;
    s->C[1][1][1] = -393.800200;
    s->C[1][1][2] = 455.646000;
    s->C[1][1][3] = 700.297000;
    s->C[1][1][4] = -119.799600;
    s->C[1][1][5] = 157.471600;
    s->C[2][0][0] = 255.000000;
    s->C[2][0][1] = 94.352850;
    s->C[2][0][2] = -45.886970;
    s->C[2][0][3] = -299.649600;
    s->C[2][0][4] = 17.276310;
    s->C[2][0][5] = -58.124870;
    s->C[2][1][0] = 1016.000000;
    s->C[2][1][1] = 548.444000;
    s->C[2][1][2] = -347.929400;
    s->C[2][1][3] = -1185.152000;
    s->C[2][1][4] = 163.892800;
    s->C[2][1][5] = -197.154000;
    s->Et[0][0] = 1462.000000;
    s->Et[0][1] = 20839.000000;
    s->Et[1][0] = 1752.000000;
    s->Et[1][1] = 17517.000000;
    s->Et[2][0] = 1607.000000;
    s->Et[2][1] = 24546.000000;
    s->W[0][0][0] = 5.204770;
    s->W[0][0][1] = 1.209207;
    s->W[0][0][2] = 0.786851;
    s->W[0][0][3] = 0.349621;
    s->W[0][0][4] = 0.408994;
    s->W[0][0][5] = -0.445588;
    s->W[0][1][0] = 19.220400;
    s->W[0][1][1] = 3.588825;
    s->W[0][1][2] = 1.913868;
    s->W[0][1][3] = 3.506777;
    s->W[0][1][4] = 1.358647;
    s->W[0][1][5] = 0.422635;
    s->W[1][0][0] = 4.430156;
    s->W[1][0][1] = 0.443817;
    s->W[1][0][2] = 0.027152;
    s->W[1][0][3] = 0.154499;
    s->W[1][0][4] = -0.066661;
    s->W[1][0][5] = -0.080471;
    s->W[1][1][0] = 16.607560;
    s->W[1][1][1] = 5.577964;
    s->W[1][1][2] = 0.354493;
    s->W[1][1][3] = 0.360068;
    s->W[1][1][4] = -0.479014;
    s->W[1][1][5] = -0.593818;
    s->W[2][0][0] = 5.394954;
    s->W[2][0][1] = 0.280039;
    s->W[2][0][2] = 0.037738;
    s->W[2][0][3] = 0.158206;
    s->W[2][0][4] = 0.190283;
    s->W[2][0][5] = -0.282106;
    s->W[2][1][0] = 20.558000;
    s->W[2][1][1] = 3.098242;
    s->W[2][1][2] = -1.602062;
    s->W[2][1][3] = 0.427116;
    s->W[2][1][4] = 1.136129;
    s->W[2][1][5] = -0.365753;
    s->lambda[0] = 0.046400;
    s->lambda[1] = 0.000000;
    s->lambda[2] = 0.464200;
    s->Nc = 3;
    s->N = 5;
    s->M = 2;
    s->inputMeans[0] = 21.484850;
    s->inputMeans[1] = 0.145688;
    s->inputMeans[2] = 0.429726;
    s->inputMeans[3] = 0.709091;
    s->inputMeans[4] = 0.771717;
    s->inputStd[0] = 8.588651;
    s->inputStd[1] = 0.322621;
    s->inputStd[2] = 0.446582;
    s->inputStd[3] = 0.705117;
    s->inputStd[4] = 0.455133;
    s->distanceMeasure[0] = 0.000081;
    s->distanceMeasure[1] = 0.002143;
    s->distanceMeasure[2] = 0.001548;
    s->distanceMeasure[3] = 0.000981;
    s->distanceMeasure[4] = 0.001519;
    s->Nv[0] = 43.000000;
    s->Nv[1] = 74.000000;
    s->Nv[2] = 48.000000;
}
void pln1_usage() {
    pln1_t pln1;
    init_memory_pln1(&pln1);
    load_values_pln1(&pln1);
    
    // Use pln1 here
    
    free_memory_pln1(&pln1);
}
