#include<cstdint>
#include<iostream>

using namespace std;

/*
A blockchain is made up of a series of blocks which contain data and each block contains a cryptographic representation of the previous block, which means that it becomes very hard to change the contents of any block without then needing to change every subsequent one; hence where the blockchain essentially gets its immutable properties.
*/

class Block {
public:
	string sPrevHash; // Each block is linked to the previous block
	Block(unit32_t nIndexIn, const string &sDataIn);
	string GetHash();
	void MineBlock(uint32_t nDifficulty);

private:
	unit32_t _nIndex;
	int64_t _nNonce;
	string _sData;
	string _sHash;
	time_t _tTime;

	string _CalculateHash() const;
};