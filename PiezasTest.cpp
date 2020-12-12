/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, dropPieceXCheck)
{
	Piezas o;
	Piece ori = o.dropPiece(0);
	ASSERT_EQ(ori, X);
}

TEST(PiezasTest, dropPieceOCheck)
{
	Piezas o;
	o.dropPiece(0);
	Piece ori = o.dropPiece(0);
	ASSERT_EQ(ori, O);
}

TEST(PiezasTest, dropPieceInvalidCheck)
{
	Piezas o;
	Piece ori = o.dropPiece(6);
	ASSERT_EQ(ori, Invalid);
}

TEST(PiezasTest, dropPieceFullCheck)
{
	Piezas o;
	o.dropPiece(0);
	o.dropPiece(0);
	o.dropPiece(0);
	Piece ori = o.dropPiece(0);
	ASSERT_EQ(ori, Blank);
}

//Test pieceAt
TEST(PiezasTest, pieceAtFirstCheck)
{
	Piezas o;
	o.dropPiece(0);
	Piece ori = o.pieceAt(0,0);
	ASSERT_EQ(ori, X);
}

TEST(PiezasTest, pieceAtSecondCheck)
{
	Piezas o;
	o.dropPiece(0);
	o.dropPiece(0);
	Piece ori = o.pieceAt(1,0);
	ASSERT_EQ(ori, O);
}

TEST(PiezasTest, pieceAtBlankCheck)
{
	Piezas o;
	Piece ori = o.pieceAt(0,0);
	ASSERT_EQ(ori, Blank);
}

TEST(PiezasTest, pieceAtInvalidCheck)
{
	Piezas o;
	Piece ori = o.pieceAt(0,6);
	ASSERT_EQ(ori, Invalid);
}

//Test Reset
TEST(PiezasTest, ResetCheck)
{
	Piezas o;
	o.dropPiece(0);
	o.reset();
	Piece ori = o.pieceAt(0,0);
	ASSERT_EQ(ori, Blank);
}

//Test gameState
TEST(PiezasTest, gameStateUnfinishedCheck)
{
	Piezas o;
	Piece ori = o.gameState();
	ASSERT_EQ(ori, Invalid);
}

TEST(PiezasTest, gameStateTieCheck)
{
	Piezas o;
	o.dropPiece(0);
	o.dropPiece(0);
	o.dropPiece(0);
	o.dropPiece(1);
	o.dropPiece(1);
	o.dropPiece(1);
	o.dropPiece(2);
	o.dropPiece(2);
	o.dropPiece(2);
	o.dropPiece(3);
	o.dropPiece(3);
	o.dropPiece(3);
	Piece ori = o.gameState();
	ASSERT_EQ(ori, Blank);
}

TEST(PiezasTest, gameStateXCheck)
{
	Piezas o;
	o.dropPiece(0);
	o.dropPiece(0);
	o.dropPiece(2);
	o.dropPiece(2);
	o.dropPiece(1);
	o.dropPiece(0);
	o.dropPiece(3);
	o.dropPiece(2);
	o.dropPiece(1);
	o.dropPiece(3);
	o.dropPiece(1);
	o.dropPiece(3);
	Piece ori = o.gameState();
	ASSERT_EQ(ori, X);
}

TEST(PiezasTest, gameStateOCheck)
{
	Piezas o;
	o.dropPiece(0);
	o.dropPiece(0);
	o.dropPiece(1);
	o.dropPiece(1);
	o.dropPiece(2);
	o.dropPiece(2);
	o.dropPiece(0);
	o.dropPiece(3);
	o.dropPiece(2);
	o.dropPiece(3);
	o.dropPiece(3);
	o.dropPiece(1);
	Piece ori = o.gameState();
	ASSERT_EQ(ori, O);
}

TEST(PiezasTest, gameStateXColCheck)
{
	Piezas o;
	o.dropPiece(0);
	o.dropPiece(1);
	o.dropPiece(0);
	o.dropPiece(2);
	o.dropPiece(3);
	o.dropPiece(2);
	o.dropPiece(1);
	o.dropPiece(3);
	o.dropPiece(0);
	o.dropPiece(3);
	o.dropPiece(2);
	o.dropPiece(1);
	Piece ori = o.gameState();
	ASSERT_EQ(ori, X);
}

TEST(PiezasTest, gameStateOColCheck)
{
	Piezas o;
	o.dropPiece(1);
	o.dropPiece(0);
	o.dropPiece(2);
	o.dropPiece(3);
	o.dropPiece(3);
	o.dropPiece(0);
	o.dropPiece(1);
	o.dropPiece(2);
	o.dropPiece(2);
	o.dropPiece(0);
	o.dropPiece(3);
	o.dropPiece(1);
	Piece ori = o.gameState();
	ASSERT_EQ(ori, O);
}