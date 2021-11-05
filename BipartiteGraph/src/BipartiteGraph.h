#pragma once

#include "BipartiteNode.h"
#include <vector>
#include <memory>

template <class T>
class BipartiteGraph {
public:
	// == constructors ==
	BipartiteGraph() {}
	// == methods ==
	// Add equation node
	inline void addE(std::unique_ptr<BipartiteNode<T>>& e);
	// Add variable node
	inline void addV(std::unique_ptr<BipartiteNode<T>>& v);
	// Get all equations nodes
	inline std::vector<std::unique_ptr<BipartiteNode<T>>>& getEqs();
	// Get all variables nodes
	inline std::vector<std::unique_ptr<BipartiteNode<T>>>& getVars();
	// Get number of equations nodes
	inline size_t ne() const { return this->Ve.size(); };
	// Get number of  nodes
	inline size_t nv() const { return this->Vv.size(); };

private:
	// == properties ==
	std::vector<std::unique_ptr<BipartiteNode<T>>> Ve;
	std::vector<std::unique_ptr<BipartiteNode<T>>> Vv;
};

// === BipartiteGraph implementation ==

template<class T>
inline void BipartiteGraph<T>::addE(std::unique_ptr<BipartiteNode<T>>& e)
{
	// and only if not found before. this avoids duplicated nodes
	if (std::find(Ve.begin(), Ve.end(), e) == Ve.end())
		Ve.push_back(std::move(e));
}

template<class T>
inline void BipartiteGraph<T>::addV(std::unique_ptr<BipartiteNode<T>>& v)
{
	// and only if not found before. this avoids duplicated nodes
	if (std::find(Vv.begin(), Vv.end(), v) == Vv.end())
		Vv.push_back(std::move(v));
}

template<class T>
inline std::vector<std::unique_ptr<BipartiteNode<T>>>& BipartiteGraph<T>::getEqs()
{
	return this->Ve;
}

template<class T>
inline std::vector<std::unique_ptr<BipartiteNode<T>>>& BipartiteGraph<T>::getVars()
{
	return this->Vv;
}
