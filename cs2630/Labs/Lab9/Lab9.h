#include <cstddef>
#include <queue>

typedef int InfoType;

class BSTree
{
public:
   BSTree() { tree = NULL; }
	~BSTree() { Clean( tree ); } 
   void Insert ( InfoType x ) {  Insert ( tree, x ); }
   bool Delete ( InfoType x )  { return Delete ( tree, x );  }
	void LevelPrint() const;
	void RevOrderPrint() const { RevOrderPrint( tree ); }
	int Depth() { return Depth( tree ); }

private:
   struct TreeNode
   { 
      InfoType info;    
      TreeNode *left, *right;
      TreeNode( InfoType x ) { info = x; left = right = NULL; }   
   };
   TreeNode * tree;
   void Insert ( TreeNode * & t, InfoType x );
   bool Delete ( TreeNode * & t, InfoType x );
	void Clean( TreeNode * t );
	int Depth ( const TreeNode * t ) const;
	void BSTree::RevOrderPrint( const TreeNode * t ) const;
};