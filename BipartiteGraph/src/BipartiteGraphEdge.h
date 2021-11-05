#pragma once

#include <memory>

// forward declarations
template <class T>
class BipartiteNode;
template <class T>
class BipartiteEdge;

template <class T>
using BipartiteNodePtr = std::shared_ptr<BipartiteNode<T>>;
template <class T>
using BipartiteEdgePtr = std::shared_ptr<BipartiteEdge<T>>;

template <class T>
class BipartiteEdge {
public:
	// == constructors ==
	BipartiteEdge(
		BipartiteNode<T>* const n1,
		BipartiteNode<T>* const n2,
		const BipartiteEdgePtr<T>& next);

	// == methods ==
	// get first node pointer
	BipartiteNode<T>* getNode1() const;
	// get second node pointer
	BipartiteNode<T>* getNode2() const;
	// get reference to next edge
	BipartiteEdgePtr<T>& getNext();

private:
	// == properties ==
	// pointer to first connecting node
	BipartiteNode<T>* node1;
	// pointer to second connecting node
	BipartiteNode<T>* node2;
	// pointer to the next edge (linked list style)
	BipartiteEdgePtr<T> next;
};

// === BipartiteEdge implementation ==

template<class T>
inline BipartiteEdge<T>::BipartiteEdge(
	BipartiteNode<T>* const n1,
	BipartiteNode<T>* const n2,
	const BipartiteEdgePtr<T>& next)
{
	this->node1 = n1;
	this->node2 = n2;
	this->next = next;
}

template<class T>
inline BipartiteNode<T>* BipartiteEdge<T>::getNode1() const
{
	return this->node1;
}

template<class T>
inline BipartiteNode<T>* BipartiteEdge<T>::getNode2() const
{
	return this->node2;
}

template<class T>
inline BipartiteEdgePtr<T>& BipartiteEdge<T>::getNext()
{
	return this->next;
}

