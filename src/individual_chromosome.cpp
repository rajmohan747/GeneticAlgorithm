#include "individual_chromosome.h"



char ChromosomeGenerator::mutatedGenes(std::string genes)
{
    int range      = genes.size();         
    int random_int = (rand()%range); 
    return genes[random_int];
}



std::string ChromosomeGenerator::createChromosome(std::string targetString,std::string genes)
{
    std::string chromosome = "";
            
    for(int i=0; i < targetString.size(); i++)
    {
        chromosome += mutatedGenes(genes);
    }
    return chromosome;
}
    



    // /**
    // * @brief  Constructor for the GeneticAlgorithm
    // */
    // IndividualChromosome::IndividualChromosome(std::string &childChromosome,std::string &targetString)
    // {
    //     //ROS_INFO("GeneticAlgorithm Constructor called");

    //     this->m_chromosome     = childChromosome;

    //     this->m_fitnessScore   = calculateFitness(targetString);
    //     std::cout << childChromosome << " :  "  << m_fitnessScore << std::endl;
    //     // m_targetString = "Testing";
    //     // m_chromosome   = "Test";

    //     // int score = calculateFitness();
    //     // ROS_INFO("Current score is : %d",score);
    //     // std::string chromo = createChromosome();
    //     // ROS_INFO("Current chromosome : %s",chromo.c_str());


    // }

    // /**
    // * @brief  Destructor for the GeneticAlgorithm
    // */

    // IndividualChromosome::~IndividualChromosome()
    // {

    // }


void IndividualChromosome::initChromosome(std::string &childChromosome,std::string &targetString)
{
        this->m_chromosome     = childChromosome;

        this->m_fitnessScore   = calculateFitness(targetString);
}
int IndividualChromosome::calculateFitness(std::string &targetString)
{
    int fitnessScore = 0;
    for(int i=0;i< targetString.size();i++)
    {
        if(m_chromosome[i] != targetString[i])
        {
            fitnessScore++;
        }
    }
    return fitnessScore;
}