#include "genetic_algorithm.h"
#include <ros/console.h> 










GeneticAlgorithm::GeneticAlgorithm()
{
    ROS_INFO("Genetic Algorithm Initialized");    
}

GeneticAlgorithm::~GeneticAlgorithm()
{

}



IndividualChromosome GeneticAlgorithm::matingProcess(IndividualChromosome parent1,IndividualChromosome parent2)
{
    std::string childChromosome = "";
    //ROS_INFO("Here  : %d",parent1.m_chromosome.size());
    for(int i =0; i < parent1.m_chromosome.size(); i++)
    {
        double probablity =  (rand() % 100)*0.01;
        if(probablity < 0.4)
        {
           // ROS_ERROR("In first %f",probablity);
            childChromosome += parent1.m_chromosome[i];
        }
        // if prob is between 0.4 and 0.8, insert 
        // gene from parent 2 
        else if(probablity < 0.8)
        {
            //ROS_ERROR("In middle %f ",probablity);
            childChromosome += parent2.m_chromosome[i];
        }
        else
        {
            //ROS_WARN("Here at end %f",probablity);
            childChromosome +=  m_generator.mutatedGenes(m_generator.m_genes);
        }
        

    }
    IndividualChromosome indChromo;
    indChromo.initChromosome(childChromosome,m_generator.m_targetString);
    return indChromo;
    

}




void GeneticAlgorithm::algorithmFlow(std::vector<IndividualChromosome> &geneticPopulation,std::vector<IndividualChromosome> &newPopulation)
{
    sort(geneticPopulation.begin(), geneticPopulation.end());       


    int newSize = (10*POPULATION_SIZE)/100;
    for(int i = 0; i< newSize ; i++)
    {
        newPopulation.push_back(geneticPopulation[i]);
    }

    //ROS_INFO("Lowest score is : %d",geneticPopulation[0].m_fitnessScore);
    //::cout << geneticPopulation[0].m_chromosome << std::endl;    

    int offSpringSize = (90*POPULATION_SIZE)/100;
    for (int i=0; i< offSpringSize; i++)
    {
        int random_int = rand()% 50;
        IndividualChromosome parent1 = geneticPopulation[random_int];
        random_int     = rand()% 50;
        IndividualChromosome parent2   = geneticPopulation[random_int];
        IndividualChromosome offSpring = matingProcess(parent1,parent2);
        newPopulation.push_back(offSpring);
    }


}

// Overloading < operator 
bool operator<(const IndividualChromosome &ind1, const IndividualChromosome &ind2) 
{ 
    return ind1.m_fitnessScore < ind2.m_fitnessScore; 
} 





/**
* @brief Main function
*/
int main(int argc, char** argv)
{

    ros::init(argc, argv, "genetic_algorithm");
    ros::NodeHandle nh;   
    ros::Rate rate(20);
    int generation = 0;

    GeneticAlgorithm genAlgorithm;

    std::vector<IndividualChromosome> chromoPopulation;
    std::vector<IndividualChromosome> newPopulation;
    
    ChromosomeGenerator chromoGenerator;
    srand (time(NULL));

    for(int i =0; i < POPULATION_SIZE;i++)
    {
        std::string childChromosome = chromoGenerator.createChromosome(chromoGenerator.m_targetString,chromoGenerator.m_genes);
        IndividualChromosome indChromo;
        indChromo.initChromosome(childChromosome,chromoGenerator.m_targetString);
        chromoPopulation.push_back(indChromo);
    }


    while(ros::ok())
    {
        if(chromoPopulation[0].m_fitnessScore > 0)
        {
            newPopulation.clear();
            genAlgorithm.algorithmFlow(chromoPopulation,newPopulation);
            chromoPopulation = newPopulation;

            cout<< "Generation: " << generation << "\t"; 
            //cout << "New size :" << newPopulation.size()<< "\t";
            cout<< "String: "<< chromoPopulation[0].m_chromosome <<"\t"; 
            cout<< "Fitness: "<< chromoPopulation[0].m_fitnessScore << "\n";

             generation ++;
         }
        rate.sleep();
        ros::spinOnce();
    }
    ros::shutdown();
    return 0;
}







