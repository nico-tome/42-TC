/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:29:31 by ntome             #+#    #+#             */
/*   Updated: 2026/03/27 13:02:43 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <iostream>
# include <algorithm>

template <typename T>
class PmergeMe
{
private:
	T _container;

public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &src);
	~PmergeMe(void);
	PmergeMe &operator=(const PmergeMe &src);

	void			sort(unsigned int pairSize);
	void			sortPair(int pairSize);
	void			swapN(unsigned int indexDst, unsigned int indexSrc, unsigned int n);
	int				calcJacobsthal(unsigned int index);
	void			printValues(void);
	void			addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);
	unsigned int	size();
};

//Constructor
template <typename T>
PmergeMe<T>::PmergeMe(void) {}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

template <typename T>
PmergeMe<T>::~PmergeMe(void) {}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe &src)
{
	if (this != &src)
		_container = T(src._container);
	return *this;
}

//Utils
template <typename T>
int PmergeMe<T>::calcJacobsthal(unsigned int index) {
	if (index <= 1)
		return (0);
	if (index == 2)
		return (1);
	return (calcJacobsthal(index - 2) * 2 + calcJacobsthal(index - 1));
}

template <typename T>
void PmergeMe<T>::swapN(unsigned int indexDst, unsigned int indexSrc, unsigned int n) {
	int tmp;
	for (unsigned int i = 0; i < n; i++) {
		tmp = _container[indexDst + i];
		_container[indexDst + i] = _container[indexSrc + i];
		_container[indexSrc + i] = tmp;
	}
}

template <typename T>
void PmergeMe<T>::sortPair(int pairSize)
{
	int	containerSize = _container.size();
	for (int i = 0; i + pairSize * 2 <= containerSize; i += pairSize * 2) {
		int n1 = _container[i + (pairSize - 1)];
		int n2 = _container[i + (pairSize * 2 - 1)];
		if (n1 > n2)
			swapN(i, i + pairSize, pairSize);
	}

	if (pairSize * 4 <= containerSize)
		return (sort(pairSize * 2));
}

template <typename T>
void PmergeMe<T>::sort(unsigned int pairSize)
{
	sortPair(pairSize);

	// Init pends, same as usual, but we don't delete element because its faster.
	unsigned int currentPair = 0;
	unsigned int i = 0;
	T pend;
	T nonParticipating;
	T newContainer;

	unsigned int size = _container.size();

	while (i < size)
	{
		if (i + pairSize <= size) {
			for (unsigned int j = 0; j < pairSize; j++) {
				if (currentPair % 2 == 0 && currentPair > 1)
					pend.push_back(_container[i + j]);
				else
					nonParticipating.push_back(_container[i + j]);
			}
		} else {
			while (i++ < size - 1)
				nonParticipating.push_back(_container[i]);;
		}
		currentPair++;
		i += pairSize;
	}

	_container.swap(newContainer);
	
	int jacobIndex = 4;

	while (!pend.empty())
	{
		unsigned int pairCount = pend.size() / pairSize;
		unsigned int jacobDiff = calcJacobsthal(jacobIndex) - calcJacobsthal(jacobIndex - 1);
		unsigned int pairToInsert = (jacobDiff * (jacobDiff < pairCount)) + (pairCount * (jacobDiff > pairCount)); //replace if else

		for (int pair = pairToInsert; pair > 0; --pair)
		{
			T keys;
			for (unsigned int i = pairSize; i <= _container.size(); i += pairSize)
				keys.push_back(_container[i - 1]);
			
			int value = pend[pairSize * pair - 1];
			typename T::iterator pos = 	std::lower_bound(keys.begin(), keys.end(), value);
			unsigned int insertIndex = std::distance(keys.begin(), pos) * pairSize;

			_container.insert(
				_container.begin() + insertIndex,
				pend.begin() + pairSize * (pair - 1),
				pend.begin() + pairSize * pair
			);

			pend.erase(
				pend.begin() + pairSize * (pair - 1),
				pend.begin() + pairSize * pair
			);
		}

		jacobIndex++;
	}
	
	for (typename T::iterator it = nonParticipating.begin(); it != nonParticipating.end(); it++)
		_container.push_back(*it);
}

template <typename T>
void PmergeMe<T>::printValues(void)
{
	for (typename T::iterator it = _container.begin(); it != _container.end(); ++it)
		std::cout << *it << " ";
}

template <typename T>
void PmergeMe<T>::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	_container.insert(_container.end(), start, end);
}

template <typename T>
unsigned int PmergeMe<T>::size()
{
	return _container.size();
}

#endif