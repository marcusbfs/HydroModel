#pragma once

#include "BipartiteGraph.h"

#include <vector>

enum class BipartiteGraphFlags : int {
	/** Bit flag colored */
	COLORED = 0x0001,
	/** Bit flag deleted */
	DELETED = 0x0002,
	/** Bit flag marked */
	MARKED = 0x0004,
	/** Bit flag under-constrained */
	UNDER = 0x0010,
	/** Bit flag over-constrained */
	OVER = 0x0020
};

template <class T>
class BipartiteGraphAlgorihtms {
public:
	inline static int AugmentMatching(
		BipartiteGraph<T>* const G, BipartiteNode<T>* const ve
		)
	{
		// try a direct connection
		auto e = ve->getEdges();
		while (e != nullptr)
		{
			BipartiteNode<T>* vv = e->getNode2();

			if (
				vv->getConnected() == nullptr
				&& !(vv->hasFlag((int)BipartiteGraphFlags::DELETED))
				)
			{
				ve->connect(*vv);
				return RET_SUCCESS;
			}
			e = e->getNext();
		}
		// try an alternating path
		e = ve->getEdges();
		while (e != nullptr)
		{
			BipartiteNode<T>* vv = e->getNode2();
			ve->setFlag((int)BipartiteGraphFlags::COLORED);
			BipartiteNode<T>* ve2 = vv->getConnected();

			if (!(vv->hasFlag((int)BipartiteGraphFlags::DELETED))
				&& ve2 != nullptr
				&& !(ve2->hasFlag((int)BipartiteGraphFlags::COLORED))
				&& AugmentMatching(G, ve2) == RET_SUCCESS)
			{
				ve->connect(*vv);
				return RET_SUCCESS;
			}
			e = e->getNext();
		}
		return RET_FAILED;
	}

	inline static int MaximumMatching(BipartiteGraph<T>* const G) {
		bool isPerfect = true;
		// augment match one by one
		for (auto& ve : G->getEqs())
		{
			if (ve->getConnected() == nullptr
				&& AugmentMatching(G, ve.get()) != RET_SUCCESS)
			{
				isPerfect = false;
			}
				// uncolour all nodes
				for (auto& ve2 : G->getEqs())
					ve2->removeFlag((int)BipartiteGraphFlags::COLORED);
		}
		return isPerfect;
	}

	// Divide domain into overdetermined and undertermined
	// returns true if the system is perfectly matched (n_over = n_under = 0)
	inline static bool DulmageMendelshon(BipartiteGraph<T>* const G, int& n_over, int& n_under) {
		n_over = n_under = 0;
		// mark over
		for (auto& ve : G->getEqs())
			if (ve->getConnected() == nullptr)
				n_over += markAlternating(ve.get(), (int)BipartiteGraphFlags::OVER);

		// mark under
		for (auto& vv : G->getVars())
			if (vv->getConnected() == nullptr)
				n_under += markAlternating(vv.get(), (int)BipartiteGraphFlags::UNDER);

		return (n_over == 0 && n_under == 0);
	}

	inline static int markAlternating(BipartiteNode<T>* const v, const int& flag) {
		int nMarked = 0;
		if (v->hasFlag(flag))
			return nMarked; // already marked
		// colour ve
		v->setFlag(flag);
		++nMarked;

		// look for alternating paths and mark it
		auto e = v->getEdges();
		while (e != nullptr)
		{
			BipartiteNode<T>* vv = e->getNode2();
			BipartiteNode<T>* ve2 = vv->getConnected();
			if (ve2 != nullptr
				&& ve2 != v
				&& !ve2->hasFlag(flag)
				)
				nMarked += markAlternating(ve2, flag);

			e = e->getNext();
		}
		return nMarked;
	}
public:
	/** Algorithm successfully returned */
	static const int RET_SUCCESS = 1;
	/** Algorithm failed */
	static const int RET_FAILED = 0;
	/** Algorithm returned in an intermediate step */
	static const int RET_STEP = -1;
private:
	// cannot be instantieted
	BipartiteGraphAlgorihtms() {};
};
