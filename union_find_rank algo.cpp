#include<stdio.h>
#include<malloc.h>
#define ll long long int
struct Edge
{
	ll src,dest;
};
struct node
{
	ll v,e;
	struct Edge* edge;
};
struct subset
{
ll parent;
ll rank;	
};
struct node* creategraph(ll verti,ll edg)
{
	struct node* node1=(struct node*)malloc(sizeof(struct node));
	node1->v=verti;
	node1->e=edg;
	node1->edge=(struct Edge*)malloc(verti*sizeof(struct Edge));
	return node1;
}
ll find(struct subset subset[],ll value)
{
	if(subset[value].parent!=value)
		subset[value].parent=find(subset,subset[value].parent);
	
	return subset[value].parent; 
}
void union1(struct subset subset[],ll x,ll y)
{
	ll xt=find(subset,x);
	ll yt=find(subset,y);
	if(subset[xt].rank<subset[yt].rank)
	{
		subset[xt].parent=yt;
	}
	else if(subset[xt].rank>subset[yt].rank)
	
	{
		subset[yt].parent=xt;
	}
	else
	{
		subset[yt].parent=xt;
		subset[xt].rank++;
	}
}
ll cycle(struct node* node)
{
	ll i;
	struct subset* subset=(struct subset*)malloc(node->v*sizeof(struct subset));
	for(i=1;i<=node->v;i++)
	{
		subset[i].parent=i;
		subset[i].rank=0;
	}
	for(i=1;i<=node->e;i++)
	{
		ll x=find(subset,node->edge[i].src);
		ll y=find(subset,node->edge[i].dest);
		if(x==y) return 1;
		union1(subset,x,y);
	}
}
int main()
{
		ll verti=7;
	ll edg=7;
	struct node* node=creategraph(verti,edg);
	node->edge[1].src=1;
	node->edge[1].dest=2;
	node->edge[2].src=2;
	node->edge[2].dest=3;
	node->edge[3].src=3;
	node->edge[3].dest=5;
	node->edge[4].src=5;
	node->edge[4].dest=6;
	node->edge[5].src=6;
	node->edge[5].dest=7;
	node->edge[6].src=3;
	node->edge[6].dest=4;
	node->edge[7].src=7;
	node->edge[7].dest=4;
	if(cycle(node)!=1){printf("no cycle");}
	else{printf("cycle");	}
	return 0;
	}
