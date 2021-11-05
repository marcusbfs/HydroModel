#pragma once

#include <vector>
#include <string>
#include <memory>

#include "BipartiteGraphEdge.h"

template <class T>
class BipartiteNode {
public:
	// == constructors ==
	// Creates a node for the given object.
	BipartiteNode(
		const T& object
		);

	// == Methods ==
	/*Add a new edge between two nodes (this and the @a node).
	  This function should be called only in one of the sides, because the vertex is added
	  in both.
	 */
	inline void addEdge(BipartiteNode<T>& node);
	// return trues if node is found on edge->node2 (checks all edges)
	inline bool findEdge(const BipartiteNode<T>& node) const;
	/**
	Connects two nodes.

	 <p>Before the new connection is made the current connection removed because
	 in a matching each node has a unique connection.

	 <p>If the given node is <code>null< / code> the current connection is removed
	 and the node remains disconnected.

	 <p><b>NOTE< / b> each node can have any number of edges but only one connection.
	*/
	inline void connect(BipartiteNode<T>& node);
	// Adds the given bit flag f to the node
	inline void setFlag(const int& f) {
		flag |= f;
	}
	// Remove the given bit flag f to the node
	inline void removeFlag(const int& f) {
		flag &= ~f;
	}
	// Check the given bit flag f to the node
	inline bool hasFlag(const int& f) const {
		return (flag & f) != 0;
	}
	// Get the given bit flag f to the node
	inline int getFlag() const {
		return this->flag;
	}

	// == getters ==
	// get connected object
	inline BipartiteNode<T>* getConnected() const {
		return this->connected;
	}
	// return pointer to head edge of node
	inline BipartiteEdgePtr<T> getEdges() const {
		return this->edges;
	}
	// get object data
	inline T  getObject() const {
		return this->object;
	}

private:
	// == properties ==
	/// Flag of the node.
	int flag = 0;
	// Node connected with this one.
	BipartiteNode<T>* connected;
	// All edges of this Node.
	BipartiteEdgePtr<T> edges;
	// The node object.
	T object;
};

// === BipartiteNode implementation ==

template<class T>
inline BipartiteNode<T>::BipartiteNode(const T& object)
{
	flag = 0;
	connected = nullptr;
	edges = nullptr;
	this->object = object;
}

template<class T>
inline void BipartiteNode<T>::addEdge(BipartiteNode<T>& node)
{
	//BipartiteEdge( // this is only for reference when 
	// // constructing BipartiteEdge
	//	BipartiteNode<T>* const n1,
	//	BipartiteNode<T>* const n2,
	//	const BipartiteEdgePtr<T>& next);

	if (!findEdge(node))
		this->edges = std::make_shared<BipartiteEdge<T>>
		(this, &node, this->edges);

	if (!node.findEdge(*this))
		node.edges = std::make_shared<BipartiteEdge<T>>
		(&node, this, node.edges);
}
template<class T>
inline bool BipartiteNode<T>::findEdge(const BipartiteNode<T>& node) const
{
	BipartiteEdgePtr<T> e = edges;
	while (e != nullptr) {
		if (e->getNode2() == &node)
			return true;
		e = e->getNext();
	}
	return false;
}
template<class T>
inline void BipartiteNode<T>::connect(BipartiteNode<T>& node)
{
	if (connected != nullptr) {
		connected->connected = nullptr;
	}
	connected = &node;
	if (&node != nullptr)
		node.connected = this;
}
