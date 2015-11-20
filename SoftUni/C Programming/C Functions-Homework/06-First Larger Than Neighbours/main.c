/* 
 Write a method that returns the index of the first element in array
 that is larger than its neighbors, or -1 if there's no such element.
 */

#include <stdio.h>
#include <stdlib.h>

#include "neighbors.h"

int main()
{
    int sequenceOne[] = {1, 3, 4, 5, 1, 0, 5};
    int sequenceTwo[] = {1, 2, 3, 4, 5, 6, 6};
    int sequenceThree[] = {1, 1, 1};
    
    int lenghtSequenceOne = LENGHT_ARRAY(sequenceOne);
    int lenghtSequenceTwo = LENGHT_ARRAY(sequenceTwo);
    int lenghtSequenceThree = LENGHT_ARRAY(sequenceThree);
    
    int index_sequenceOne = get_larger_neighbors_index(sequenceOne, 
                                                       lenghtSequenceOne);
    printf("index sequenceOne %d\n", index_sequenceOne);
    
    int index_sequenceTwo = get_larger_neighbors_index(sequenceTwo, 
                                                       lenghtSequenceTwo);
    printf("index sequenceTwo %d\n", index_sequenceTwo);
    
    
    int index_sequenceThree = get_larger_neighbors_index(sequenceThree, 
                                                         lenghtSequenceThree);
    printf("index sequenceThree %d\n", index_sequenceThree);

    return (EXIT_SUCCESS);
}

