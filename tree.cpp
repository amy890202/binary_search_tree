//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "tree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
int count_node;
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
  Form1 -> Memo1 -> Lines -> Clear();
	count_node=0;
}

//--------------------------------------------------------------
struct nodebst
{
	struct nodebst *leftchild;
	int data;
	struct nodebst *rightchild;
};
struct StackNode
{   struct nodebst *treenode;

    struct StackNode *next;

};
struct BSTreeCNode
{
	struct BSTreeCNode *leftchild;

    char * data;

    struct BSTreeCNode *rightchild;

};

struct DrawTreeNode
{
	struct DrawTreeNode* leftchild;

	int data;  int index;  int column;  int level;

    // int x;

    // int y;

    struct DrawTreeNode* rightchild;

};
struct nodebst *root;
struct BSTreeCNode *Croot;
String treedata="";
int open=0,firsttime=0;
struct StackNode *top;

struct DrawTreeNode* DrawRoot;

int* X;

int* Y;

String tree;



int** treenode;

void push_node(struct nodebst *node )

{ struct StackNode *old_top;

  old_top = top;

  top = (struct StackNode *) malloc (sizeof(struct StackNode));

  top->treenode = node;

  top->next = old_top;

}

struct nodebst *pop_node()
{
	struct nodebst *Tnode;

  struct StackNode *old_top;

  if (top == NULL)

  ;       // StackEmpty();

  else

  {  Tnode = top->treenode;

     old_top = top;

     top = top->next;

     free(old_top);

     return Tnode;

  }

}
struct qnode
{
	struct nodebst *treenode;
	struct qnode *next;
};
struct qnode *front,*rear;
void addq(struct nodebst *tnode)
{
	struct qnode *node;
	node = (struct qnode*)malloc(sizeof(struct qnode));
	node->treenode = tnode;
	node->next=NULL;
	if(front==NULL)
		front = node;
	else
		rear->next = node; //node接到最後面
	rear=node;  //把node設成最後

}
struct nodebst *deleteq()
{
	struct nodebst *tnode;
	struct qnode *old_front;
	if(rear==NULL)
        return NULL;
	else
	{
		tnode=front->treenode;
		old_front = front;
		front = front->next;
		free(old_front);
		return tnode;
	}
}
void levelorder(struct nodebst *node)
{
	addq(node);
	while(front!=NULL)
	{
		node = deleteq();
		if(node)
		{	treedata = treedata + " "+ IntToStr(node->data);
			if(node->leftchild!=NULL)
				addq(node->leftchild);
			if(node->rightchild!=NULL)
				addq(node->rightchild);
	}   }
}



struct nodebst *search(struct nodebst *tree ,int x)
{
	if(tree==NULL)
		return NULL;
	if(x == tree->data) return tree;
	if (x <tree->data)
	{
		return search(tree->leftchild,x);
	}
	return search(tree->rightchild,x);

}
struct nodebst *newbstnode(int x)
{
	struct nodebst *node = new struct nodebst;
	node->data = x;
	node ->leftchild = NULL;
	node ->rightchild = NULL;
	return node;
}
struct nodebst * inserttree(struct nodebst *node, int x)
{
	if(node == NULL) return newbstnode(x);
	if(x < node -> data)
		node ->leftchild = inserttree(node->leftchild,x);
	else
		node ->rightchild = inserttree(node->rightchild,x);
	return node;

}
int InsertBST(int x)

{  struct nodebst *p, *q;

    p = root; q = NULL;

    while (p != NULL)

    { q = p;

      // if (x == p->data) return 0;

      if (x < p->data)

          p = p->leftchild;

      else

          p = p->rightchild;

    }

    // p = (struct BSTreeNode *) malloc (sizeof(BSTreeNode));

	p = new struct nodebst;

    p->data = x;

    p->leftchild = p->rightchild = NULL;

    if (root == NULL)

    {   root = p;

        count_node++;

    }

    else if (x < q->data)

         {  q->leftchild = p;

            count_node++;

         }

         else

         {  q->rightchild = p;

            count_node++;

         }

    return 1;

}
void Inorder_Stack(struct nodebst * node)
{   // node = root;

  do

  {  while (node != NULL)

	 {  push_node(node);

        node = node->leftchild;

     }  // phsh all left children

     if (top != NULL)

     {  node = pop_node();

		treedata += IntToStr(node->data)+"_";

        node = node->rightchild;

     } // inorder printing and check right child

  } while ((top!=NULL)||(node!=NULL));

}

void Postorder_Stack(struct nodebst * node)

{  do

   {  while (node != NULL)

	  {
		//if(firsttime==0)
		 //	treedata = "(post)stack: "+IntToStr(node->data)+"_"+treedata;
		//else
		treedata = IntToStr(node->data)+"_"+treedata;
		//treedata += IntToStr(node->data)+"_";
	   // firsttime=1;

          push_node(node);

          node = node->rightchild;

	  }   // push all left children


      if (top != NULL)

      {   node = pop_node();

          node = node->leftchild;

      }

  } while ((top!=NULL)||(node!=NULL));
  treedata = "(post)stack: "+treedata;

}

void Preorder_Stack(struct nodebst * node)

{  do

   { while (node != NULL)

	 {
		treedata += IntToStr(node->data)+"_";

         push_node(node);

         node = node->leftchild;

	 }   // push all left children

     if (top != NULL)

     {   node = pop_node();

         node = node->rightchild;

     }

   } while ((top!=NULL)||(node!=NULL));

}
/*
void printtree()
{
	struct nodebst *p;
   //	if(temp==1)
	{
		treedata="";
		for(p=first->next;p!=first;p=p->next)
		{
			if(p==first->next)
				list=list+IntToStr(p->data);
			else
				list=list+"->"+IntToStr(p->data);
		//  ShowMessage("go");
		}
	}
}*/
int tempcount;
int Depth_BTree(struct nodebst* node, int level)

{   int depth, l_depth, r_depth;

    if (node!=NULL)

    {  //treenode[tempcount][0] = node->data;

       //treenode[tempcount][3] = site;

       //tempcount++;

       l_depth = Depth_BTree(node->leftchild, (level+1));

       r_depth = Depth_BTree(node->rightchild, (level+1));

       depth = l_depth>r_depth? l_depth : r_depth;

       return depth;

    }

    else return (level-1);

}
void determine_X(struct DrawTreeNode* node, int left, int right)

{   if (node != NULL)

    {  int m = (left+right)/2;

       X[node->index] = (m == 0) ? left : m;

       determine_X(node->leftchild, left, (m-1<left)?left:m-1);

       determine_X(node->rightchild, (m+1<right)?m+1:right, right);

    }

}

void determine_Y(struct DrawTreeNode* node, int top, int bottom, int depth)

{  int detH = (top+bottom)/(depth+1);

   for (int i=0; i<depth+1; i++)

   {  Y[i] = (detH < 10) ? 10*i : detH*i;

   }

}

struct DrawTreeNode* CopyBSTtoDT(struct nodebst* TreeRoot, int index, int depth)

{   if (TreeRoot==NULL)

    {   return NULL;

	}

    struct DrawTreeNode* copyRoot = (struct DrawTreeNode*)malloc(sizeof(DrawTreeNode));

    copyRoot->data = TreeRoot->data;

    copyRoot->index = index;

	// copyRoot->y = ceil(log(index+1)/log(2.0));

    // copyRoot->x = pow(2, (depth-copyRoot->y))+pow(2, (depth-copyRoot->y)+1)

    // *   (index-(pow(2, copyRoot->y-1)-1)-1);
  //	copyRoot->level = ceil(log(index+1)/log(2.0));
	//copyRoot->column = pow(2,(depth-copyRoot->level))+pow(2,(depthcopyRoot->level)+1)*(index-(pow(2,copyRoot->level-1)-1)-1);

	copyRoot->leftchild = CopyBSTtoDT(TreeRoot->leftchild, 2*index, depth);

	copyRoot->rightchild = CopyBSTtoDT(TreeRoot->rightchild, 2*index+1, depth);

    return copyRoot;

}

// void Draw_BST(struct DrawTreeNode* DrawRoot, int detW, int detH, int node_radius)

void Draw_BST(struct DrawTreeNode* DrawRoot, int node_radius)

{   if (DrawRoot!=NULL)

    {  int level = ceil(log(DrawRoot->index+1)/log(2.0));

       if (DrawRoot->leftchild!=NULL)

       {   Form1->Image1->Canvas->MoveTo(X[DrawRoot->index], Y[level]);

           Form1->Image1->Canvas->LineTo(X[DrawRoot->leftchild->index], Y[level+1]);

           //Form1->Image1->Canvas->MoveTo((DrawRoot->x)*detW, (DrawRoot->y)*detH);

           //Form1->Image1->Canvas->LineTo((DrawRoot->leftchild->x)*detW, (DrawRoot->leftchild->y)*detH);

       }

       if (DrawRoot->rightchild)

       {   Form1->Image1->Canvas->MoveTo(X[DrawRoot->index], Y[level]);

           Form1->Image1->Canvas->LineTo(X[DrawRoot->rightchild->index], Y[level+1]);

           //Form1->Image1->Canvas->MoveTo((DrawRoot->x)*detW, (DrawRoot->y)*detH);

           //Form1->Image1->Canvas->LineTo((DrawRoot->rightchild->x)*detW, (DrawRoot->rightchild->y)*detH);

       }

       Form1->Image1->Canvas->Ellipse(X[DrawRoot->index]- node_radius,

           Y[level] - node_radius,

           X[DrawRoot->index]+ node_radius,

           Y[level] + node_radius);

       Form1->Image1->Canvas->TextOut(X[DrawRoot->index]-5, Y[level]-7, IntToStr(DrawRoot->data));

	   //Form1->Image1->Canvas->Ellipse((X[DrawRoot->index]- node_radius,

       //         ((DrawRoot->y)*detH) - node_radius,

       //         ((DrawRoot->x)*detW)+ node_radius,

       //         ((DrawRoot->y)*detH) + node_radius);

       //Form1->Image1->Canvas->TextOutA((DrawRoot->x)*detW-5, (DrawRoot->y)*detH-8, IntToStr(DrawRoot->data));

       // Draw_BST(DrawRoot->leftchild, detW, detH, node_radius);

       // Draw_BST(DrawRoot->rightchild, detW, detH, node_radius);

       Draw_BST(DrawRoot->leftchild, node_radius);

       Draw_BST(DrawRoot->rightchild, node_radius);

    }

}

void Clear_BST(struct nodebst* BSTnode)

{   if (BSTnode != NULL)

    {   Clear_BST(BSTnode->leftchild);

        Clear_BST(BSTnode->rightchild);

        delete(BSTnode);

    }

}

void Clear_DBST(struct DrawTreeNode* DBSTnode)

{   if (DBSTnode != NULL)

    {   Clear_DBST(DBSTnode->leftchild);

        Clear_DBST(DBSTnode->rightchild);

        delete(DBSTnode);

    }

}
void inorder(struct nodebst *ptr)
{

	if(ptr)
	{
		inorder(ptr->leftchild);
	   //	ShowMessage(ptr->data);
		treedata = treedata +" "+IntToStr(ptr ->data);
		//ShowMessage(treedata);
		inorder(ptr->rightchild);
	}
}

void preorder(struct nodebst *node)
{
	if(node!=NULL)
	{
		treedata = treedata +" "+IntToStr(node ->data);
		preorder(node->leftchild);
		preorder(node->rightchild);
	}
}
void postorder(struct nodebst *node)
{
	if(node!=NULL)
	{

		postorder(node->leftchild);
		postorder(node->rightchild);
		treedata = treedata +" "+IntToStr(node ->data);
	}
}
struct nodebst *inordersucc(struct nodebst *node)
{
	struct nodebst *p = node;
	while(p->leftchild!=NULL)
		p=p->leftchild;
    return p;

}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int data = StrToInt(Edit1->Text);
	root = inserttree(root,data);
	treedata="";
	inorder(root);
	Memo1->Lines->Add(treedata);
//	datanode=newbstnode(data);
//	addq(datanode);
//	treedata="";
//	levelorder(datanode);
//	Memo1->Lines->Add(treedata);



}
//---------------------------------------------------------------------------

int deletebstnotrecursion(int x)
{
	struct nodebst *p , *father ,*k ,*f;
	p=root;
	father = NULL;
	while(p!=NULL)
	{
		if(x == p->data)//找到x所在的節點p
		{
			if(( p->leftchild == NULL) && ( p->rightchild == NULL) )
				k=NULL;    //p為樹葉節點
			else if ( p->leftchild != NULL)//p非為子節點(有子樹)
			{
				f = p;       //找出p左子樹的最右樹葉
				k = p->leftchild;
				while(k->rightchild!= NULL)
				{
					f=k;
					k = k->rightchild;
				}
				//將k挪至原p處
				if (p==f)//p沒右子樹?
					f->leftchild = k->leftchild;
				else
					f->rightchild = k->leftchild;




			}
			else   //p無左子樹
			{
				f=p;       //找出p右子樹的最左樹葉
				k=p->rightchild;
				while(k->leftchild!=NULL)
				{
					f=k;
					k=k->leftchild;
				}
				if(p==f)
					f->rightchild = k->rightchild;
				else
					f->leftchild = k->rightchild;

			}
			if(k!=NULL)  //k挪至原p處繼承p的左右指標
			{
				k->leftchild = p->leftchild;
				k->rightchild = p->rightchild;
			}
			if(father==NULL)
				root=k;
			else if(x< father->data)  //決定k是father的左或右兒子
				father->leftchild = k;
			else
				father ->rightchild =k;
			free(p);
			return 1;  //成功地刪除x，於此傳回1返回呼叫處


		}      //為找到x時應有的處理步驟
		else
		{
			father=p;
			if(x<p->data)
				p = p->leftchild;
			else
				p=p->rightchild;

		}

	}
	return 0;   //未找到x，傳回0


}

struct nodebst *deletebst(struct nodebst *node , int x)
{
	struct nodebst *temp;
	if(node == NULL)
		return node;
	if( x < node->data)
		node->leftchild = deletebst(node->leftchild,x);
	else if (x>node->data)
		node ->rightchild = deletebst(node->rightchild,x);
	else//x==node->data    找到x所在的節點
	{
		open=1;

		if((node->leftchild == NULL) || (node -> rightchild == NULL))
		{
			temp = node->leftchild? node ->leftchild: node ->rightchild; //如果左子樹不適NULL就放右子樹?
			if(temp == NULL)// 左右子樹都NULL node is a leaf itself
			{
				temp = node;
				node = NULL;
			}
			else
				*node = *temp;
			 free(temp);
		}
		else
		{
			temp = inordersucc(node->rightchild);
			node->data = temp ->data;
			node ->rightchild = deletebst(node->rightchild,temp->data);

		}
	}

	return node;



}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int data = StrToInt(Edit2->Text);
	open=0;
	root = deletebst(root , data);
	//deletebstnotrecursion(data);
	treedata="";

	inorder(root);

	if(open!=1)
	   Memo1->Lines->Add("can't find the target "+IntToStr(data));
	else
		Memo1->Lines->Add(treedata);
	//Memo1->Lines->Add(treedata);

//	datanode=newbstnode(data);
//	deleteq();
//	treedata="";
//	levelorder(datanode);
//	Memo1->Lines->Add(treedata);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
//	int a = TrackBar1->Position;
//	Edit3->Text = a;
	int n = Edit3->Text.ToInt();
	int range = Edit4->Text.ToInt();

	//for(int i=0;i<n;i++)
	int i=0;
	while(i<n)
	{   /*
		struct node *p;
	//struct node *p= new node [n];
		p = (struct nodebst *)malloc(sizeof(nodebst));

		//p[i].data = rand() % range + 1;
		p->data = rand() % range + 1;
		inserttree(p);
		*/
		int data = rand() % range + 1;
		root = inserttree(root,data);
		i++;
		//datanode=newbstnode(data);
		//addq(datanode);

	}


	treedata="";
	inorder(root);
	Memo1->Lines->Add(treedata);

//	treedata="";
//	levelorder(datanode);
//	Memo1->Lines->Add(treedata);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
    int a = TrackBar1->Position;
	Edit3->Text = a;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar2Change(TObject *Sender)
{
	int b = TrackBar2->Position;
	Edit4->Text = b;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	treedata="(pre)recursion: ";
	preorder(root);
	Memo1->Lines->Add(treedata);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	treedata="(post)recursion: ";
	postorder(root);
	Memo1->Lines->Add(treedata);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	treedata="(level)recursion: ";
	levelorder(root);
	Memo1->Lines->Add(treedata);

}
//---------------------------------------------------------------------------
/*
void __fastcall TForm1::Button7Click(TObject *Sender)
{
    int data = StrToInt(Edit1->Text);
	datanode=newbstnode(data);
	addq(datanode);
	treedata="";
	levelorder(datanode);
	Memo1->Lines->Add(treedata);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	deleteq();
    treedata="";
	levelorder(datanode);
	Memo1->Lines->Add(treedata);
}
//---------------------------------------------------------------------------
 */
void __fastcall TForm1::Button9Click(TObject *Sender)
{
	int data = StrToInt(Edit2->Text);
   //	open=0;
	//root = deletebst(root , data);
	deletebstnotrecursion(data);
	treedata="";

	inorder(root);

	Memo1->Lines->Add(treedata);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Image1->Picture->Assign(NULL);

 Image1->Canvas->Pen->Color =static_cast<TColor>( RGB(0, 0, 255));

 /*

 //Reset Node Record

 treenode = new int* [count_node];

 for (int i=0; i < count_node; i++) {

   treenode[i] = new int [4];

 }

 */

 //Tree Depth & Data Record

 tempcount=0;

 int depth = Depth_BTree(root, 1);

 Memo1->Lines->Add("depth:"+IntToStr(depth));

 //Tree Height & Width

 int tree_Height = 450;

 int tree_Width = 500;

 //Node Distance

 int total_node = pow(2, depth)-1;

 int detW = tree_Width/(total_node+1);

 int detH = tree_Height/(depth+1);

 //Node Size

 int node_radius = (detW*5/6 > detH/2) ? detH/2 : detW*5/6;

 //Find Node Coordinate

 // treenode = Find_Coordinate(treenode, count_node, total_node);

 //int temp_space, uponlevel_space;

 //int depth_node, upon_node;

 Image1->Top = 0;

 Image1->Left = 0;

 Image1->Height = tree_Height;

 Image1->Width = tree_Width;

 DrawRoot = CopyBSTtoDT(root, 1, depth);

 X = new int [total_node+2];

 Y = new int [depth+1];

 determine_X(DrawRoot, 0+node_radius, tree_Width-node_radius);

 determine_Y(DrawRoot, 0, tree_Height, depth);

 /*

 tree = "";

 for (int i=0; i<total_node+1; i++) tree += IntToStr(X[i])+" ";

 Form1->Memo1->Lines->Add(tree);

 tree = "";

 for (int j=0; j<depth+1; j++) tree += IntToStr(Y[j])+" ";

 Form1->Memo1->Lines->Add(tree);

 */

 // Draw_BST(DrawRoot, detW, detH, node_radius);

 Draw_BST(DrawRoot, node_radius);

 delete(X);

 delete(Y);

 /*

 //print level 2~depth

 int data, x, y, parent_x, parent_y, site;

 for (int i=depth; i >= 1; i--) {

  for (int j=0; j < count_node; j++) {

   if (treenode[j][2]==i) {

    data = treenode[j][0];

    x = treenode[j][1];

    y = treenode[j][2];

    for (int data_index=0; data_index < count_node; data_index++) {

     site = treenode[j][3];

     if (floor(site/2.0) == treenode[data_index][3]) {

      parent_x = treenode[data_index][1];

      parent_y = treenode[data_index][2];

      break;

     }

    }

    //Draw Line

    if (i!=1) {

     Image1->Canvas->MoveTo (x*detW, y*detH);

     Image1->Canvas->LineTo(parent_x*detW, parent_y*detH);

    }

    //Draw Node

    Image1->Canvas->Ellipse(x*detW-(node_radius),

          y*detH-(node_radius),

          x*detW+(node_radius),

          y*detH+(node_radius));

    //Node->data output

    Image1->Canvas->TextOutA(x*detW-(node_radius/2), y*detH-(node_radius/2), IntToStr(data));

   }

  }

 }

 */

 /*

 //Tree Grid

 for (int i=0; i < total_node+1; i++) {

  Image1->Canvas->MoveTo(i*detW, 0);

  Image1->Canvas->LineTo(i*detW, tree_Height);

 }

 for (int i=0; i < depth+1; i++) {

  Image1->Canvas->MoveTo(0, i*detH);

  Image1->Canvas->LineTo(tree_Width, i*detH);

 }

 */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{

	treedata="(inorder)stack: ";
	Inorder_Stack(root);
	Memo1->Lines->Add(treedata);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
    treedata="(pre)stack: ";
	Preorder_Stack(root);
	Memo1->Lines->Add(treedata);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	treedata="";
	//firsttime=0;
	Postorder_Stack(root);
	Memo1->Lines->Add(treedata);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
	int data = StrToInt(Edit1->Text);

	InsertBST(data);
	treedata="";

	inorder(root);

	Memo1->Lines->Add(treedata);
}
//---------------------------------------------------------------------------

