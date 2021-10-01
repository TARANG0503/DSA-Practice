// IN this problem of binary tree we have to find max distance(max number of edges in between) between two nodes to find the diameter for our circle
#include<bits/stdc++.h>
#include"binarytreenode.h"
int maxheight(BTnode<int> * root)
{
  int height = 0;
  if(root == NULL)
  {
    return 0;
  }
  return 1 + max( height(root->left) , height(root->right) );
}
int maxdiameter(BTnode<int> * root)
{
  if(root == NULL)
  {
    return 0;
  }
  int way1 = height(root->left) + (root->right);
  int way2 = maxdiameter(root -> left);
  int way3 = maxdiameter(root -> right);
  return max(way1 , max(way2 , way3));
}
//using inbuilt pair template
pair<int , int> heightdiameter(BTnode<int> * root)
{
  if(root == NULL)
  {
    pair<int , int> p;
    p.first = 0;
    p.second = 0;
    return p;
  }
  pair<int , int>leftans = heightdiameter(root->left);
  pair<int , int>rightans = heightdiameter(root->right);
  int leftd = leftans.second;
  int lefth = leftans.first;
  int rightd = rightans.second;
  int righth = rightans.first;

  int height = 1+max(lefth + righth);
  int diameter = max(lefth + righth + max(leftd , rightd));
  pair<int , int> p;
  p.first = height;
  p.second = diameter;
}
