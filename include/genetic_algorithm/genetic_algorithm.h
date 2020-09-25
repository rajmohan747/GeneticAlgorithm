#ifndef GENETIC_ALGORITHM
#define GENETIC_ALGORITHM


#include "individual_chromosome.h"



  /**
   * @class GeneticAlgorithm
   * @brief A controller that follows the trajectory provided by a planner.
   */






class GeneticAlgorithm : public IndividualChromosome
{
public:
        /**
     * @brief  Constructor for the GeneticAlgorithm
     */

    //GeneticAlgorithm(RosClass* m_getVariables);
    GeneticAlgorithm();
        /**
        * @brief  Destructor for the GeneticAlgorithm
        */
    ~GeneticAlgorithm();

    IndividualChromosome matingProcess(IndividualChromosome parent1,IndividualChromosome parent2);

    void algorithmFlow(std::vector<IndividualChromosome> &geneticPopulation,std::vector<IndividualChromosome> &newPopulation);

//    int m_fitnessScore;
//    std::string m_chromosome;

private:

    /*Member functions*/

    
    




    //std::string createChromosome();
    //char mutatedGenes();

    /*Member variables*/
    //std::vector<GeneticAlgorithm> m_geneticPopulation;
    ChromosomeGenerator m_chromoGenerator;




};





#endif
