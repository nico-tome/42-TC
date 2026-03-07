/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:31:46 by ntome             #+#    #+#             */
/*   Updated: 2026/03/07 22:22:00 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T *array;
		unsigned int _size;

	public:
		Array(void): array(new T()), _size(0) {};
		Array(unsigned int n): array(new T[n]()), _size(n)
		{
			for (unsigned int i = 0; i < _size; i++)
				array[i] = i;
		};
		Array(const Array &other): array(new T[other._size]()), _size(other._size)
		{
			for (unsigned int i = 0; i < _size; i++)
				array[i] = other.array[i];
		};
		~Array(void)
		{
			if (this->_size > 0)
				delete []this->array;
			else
				delete this->array;
		};
		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				if (this->_size > 0)
					delete []this->array;
				else
					delete this->array;
				if (other._size == 0)
				{
					this->array = new T();
					this->_size = 0;
					return *this;
				}
				this->_size = other._size;
				this->array = new T[this->_size]();
				for (unsigned int i = 0; i < this->_size; i++)
					this->array[i] = other.array[i];
			}
			return *this;
		};

		T &operator[](unsigned int index)
		{
			if (index >= this->_size)
				throw std::runtime_error("Index out of range");
			return array[index];
		};
		unsigned int size(void) const
		{
			return this->_size;
		};
};

#endif