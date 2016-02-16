#ifndef PMAC_CELL_H
#define PMAC_CELL_H


class Pmac_cell
{
public:
    Pmac_cell();
    void addProbability(double occ_prob, double timeStamp);
    double getLongTermOccupancyProb();
    double getProjectedOccupancyProbability(unsigned noOfProjections = 1);
    void init(double initialOccupancy, double initialFree);
    double observationSum();
    double getLastObservation();
    unsigned getMixingTime();


private:
    static const int NO_INTIAL_UPDATES = 100;
    static const int MAX_NO_OF_OBS = 2e3;
    static const double FORGET_FACTOR = 2000.0 / 2001.0;
    double occupied_count, free_count;
    double entry, exit;
    double prev_occ_prob;
    bool previous_is_occupied;
    double inital_occupied;
    double lastObservedTime;
};

#endif // PMAC_CELL_H
