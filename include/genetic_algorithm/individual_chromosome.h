#ifndef INDIVIDUAL_CHROMOSOME
#define INDIVIDUAL_CHROMOSOME

#include <iostream>
#include <ros/ros.h>
#include <bits/stdc++.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>

#define POPULATION_SIZE 100

using namespace std;
  /**
   * @class GeneticAlgorithm
   * @brief A controller that follows the trajectory provided by a planner.
   */

class ChromosomeGenerator
{
    public:
        
        std::string createChromosome(std::string targetString,std::string genes);
        char mutatedGenes(std::string genes);


        std::string m_targetString = "testing";
        std::string m_genes = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOP"\ 
    "QRSTUVWXYZ 1234567890, .-;:_!\"#%&/()=?@${[]}";
        
};



class IndividualChromosome
{
    public:
    
        // IndividualChromosome (std::string &childChromosome,std::string &targetString);
        // ~IndividualChromosome();

        void initChromosome(std::string &childChromosome,std::string &targetString);
        std::string m_chromosome;
        int m_fitnessScore;
        ChromosomeGenerator m_generator;

    private:

        /*Member functions*/
        int calculateFitness(std::string &targetString);

        
        /*Member variables*/
        
        

        
};






#endif
