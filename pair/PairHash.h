//
// Created by david on 25. 02. 2020..
//

#ifndef CHESS_PAIRHASH_H
#define CHESS_PAIRHASH_H

#include <iostream>

/**
 * Class that contains hash function for std::pair.
 *
 * @author David
 */
struct PairHash
{

	/**
	 * Hash function for std::pair.
	 *
	 * @tparam T1 First template parameter.
	 * @tparam T2 Second template parameter.
	 * @param pair Pair to get hash.
	 * @return Hash of given std::pair.
	 */
	template<typename T1, typename T2>
	std::size_t operator()(const std::pair<T1, T2> &pair) const
	{
		return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
	}
};

#endif //CHESS_PAIRHASH_H
