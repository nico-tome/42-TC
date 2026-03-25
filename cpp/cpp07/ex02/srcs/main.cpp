/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:49:12 by ntome             #+#    #+#             */
/*   Updated: 2026/03/07 22:23:33 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "color.hpp"
#include <iostream>

int main(void)
{
    unsigned int len = 10;

    Array<float> empty_array;

    Array<int> array1(len);
    Array<int> array2(len - 5);

    for (unsigned int i = 0; i < array1.size() - 1; i++ )
        array1[i] = i * 3;


    /*---------------TEST PRINT ARRAY VALUES WITH [] OPERATOR----------------*/

    std::cout << "Test with array1 size 10" << std::endl;
    
    for (unsigned int i = 0; i < array1.size(); i++)
        std::cout << array1[i] << " " ;
    std::cout << std::endl << std::endl;


    /*---------------TEST COPY ASSIGNATION----------------*/

    Array<int> array1_copy_ass;
    
    array1_copy_ass = array1;
    std::cout << "Test with the copy by assignation of array1 size 10" << std::endl;
    
    for (unsigned int i = 0; i < array1_copy_ass.size(); i++)
        std::cout << array1_copy_ass[i] << " " ;
    std::cout << std::endl << std::endl;

    for (unsigned int i = 0; i < array1.size(); i++ )
        array1[i] *= 4;


    /*---------------TEST COPY DECLARATION----------------*/

    Array<int> array1_copy(array1);

    std::cout << "Test with the declaration copy of array1 size 10" << std::endl;
    
    for (unsigned int i = 0; i < array1_copy.size(); i++)
        std::cout << array1_copy[i] << " " ;
    std::cout << std::endl << std::endl;


    /*---------------TEST COPY ARRAY1 in ARRAY2----------------*/

    array2 = array1;

    std::cout << "Test with the copy of array1 in array2" << std::endl;
    
    for (unsigned int i = 0; i < array2.size(); i++)
        std::cout << array2[i] << " " ;
    std::cout << std::endl << std::endl;


    /*---------------TEST OUT OF BOUNDS EXCEPTION----------------*/

    try {
        std::cout << "Accessing a valid index 5: " << array1[5] << std::endl;
        std::cout << "Accessing an invalid index: " << array1[len] << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}