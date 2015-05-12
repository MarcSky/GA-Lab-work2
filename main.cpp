//
//  main.cpp
//  laba2
//
//  Created by Levan Gogohia on 11.05.15.
//  Copyright (c) 2015 Levan Gogohia. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#define CHROMOSOME_SIZE 8
#define POPULATION_SIZE 10


struct chromosome{
    chromosome(){
        for(int i = 0; i < CHROMOSOME_SIZE; i++) {
            genes[i] = rand()%255;
        }
//        this->print();
    }
    void print(){
        for(int i = 0; i < CHROMOSOME_SIZE; i++) {
            std::cout<< genes[i] << " ";
        }
        std::cout << std::endl;
    }
    int genes[CHROMOSOME_SIZE];
};

// point 3

// 1 2 3 4 5 6 7 8
// 8 7 6 5 4 3 2 1

// 1 2 3 5 4 3 2 1
// 8 7 6 4 5 6 7 8
void one_point(chromosome *a1, chromosome *a2) {
    int point = rand() % CHROMOSOME_SIZE;
    std::cout<<point<<std::endl;

    std::cout<< "first "; a1->print();
    std::cout<< "second ";a2->print();
    chromosome temp;
    memcpy(&temp.genes, &a1->genes, sizeof(int) * CHROMOSOME_SIZE);
    
    memcpy(&a1->genes[point], &a2->genes[point], sizeof(int) * (CHROMOSOME_SIZE-point));
    memcpy(&a2->genes[point], &temp.genes[point], sizeof(int) * (CHROMOSOME_SIZE-point));
    memcpy(&a1->genes, &a2->genes, sizeof(int) * (point));
    memcpy(&a2->genes, &temp.genes, sizeof(int) * (point));
    
    std::cout<< "first "; a1->print();
    std::cout<< "second ";a2->print();
}

void two_point(chromosome *a1, chromosome *a2) {
    int one_point = rand() % (CHROMOSOME_SIZE/2);//1/2 (0...3)
    int two_point = 0;
    while(one_point >= two_point){
        two_point = rand() % 4 + (CHROMOSOME_SIZE / 2);//2/2 (4...7)
    }
    
    std::cout<<"one point: " << one_point << std::endl;
    std::cout<<"two_point: " << two_point << std::endl;
    a1->print();
    a2->print();
    chromosome temp;

    memcpy(&temp.genes, &a1->genes, sizeof(int) * CHROMOSOME_SIZE);
    
    memcpy(&a1->genes[one_point], &a2->genes[one_point], sizeof(int) * (two_point-one_point));
    memcpy(&a2->genes[one_point], &temp.genes[one_point], sizeof(int) * (two_point-one_point));
    
    std::cout<< "first "; a1->print();
    std::cout<< "second ";a2->print();

}

void three_point(chromosome *a1, chromosome *a2) {
    int one_point = 0;
    int two_point = 0;
    int three_point = 0;
    while(one_point >= two_point || two_point >=three_point || one_point >=three_point ){
        one_point = rand() % (CHROMOSOME_SIZE);//1/2 (0...3)
        two_point = rand() % (CHROMOSOME_SIZE);//1/2 (0...3)
        three_point = rand() % (CHROMOSOME_SIZE);//1/2 (0...3)
    }
    std::cout<<"one point: " << one_point << std::endl;
    std::cout<<"two_point: " << two_point << std::endl;
    std::cout<<"three_point: " << three_point << std::endl;

    a1->print();
    a2->print();
    
    chromosome temp;
    memcpy(&temp.genes, &a1->genes, sizeof(int) * CHROMOSOME_SIZE);
  
    memcpy(&a1->genes[one_point], &a2->genes[one_point], sizeof(int) * (two_point - one_point));
    memcpy(&a1->genes[three_point], &a2->genes[three_point], sizeof(int) * (CHROMOSOME_SIZE - three_point));
    memcpy(&a2->genes[one_point], &temp.genes[one_point],sizeof(int) * (two_point-one_point));
    memcpy(&a2->genes[three_point], &temp.genes[three_point],sizeof(int) * (CHROMOSOME_SIZE-three_point));
    
    std::cout<< "first "; a1->print();
    std::cout<< "second ";a2->print();
}

void unique_point(chromosome *a1, chromosome *a2) {
    int points[CHROMOSOME_SIZE];
    for (int i = 0 ; i < CHROMOSOME_SIZE; i++) {
        points[i] = rand()  % 255;
    }
    
    
}



int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    chromosome* population = new chromosome[2];
//    chromosome t  = three_point(population[0], population[1]);
//    t.print();
    three_point(&population[0], &population[1]);
    
    delete [] population;
    
    return 0;
}
