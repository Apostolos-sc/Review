//Author  : Moussavi M.
//Project : Reviewing C++
//File    : inheritance.cpp
//Version : 0.1
/**
 * Base class types example
*/
class A {
    public: int x;
    protected: int y;
    private: int z;
    public: void fun();//x,y,z are accessible
};

class B: protected A {
    public: int k;
    protected: int l;
    private: int m;
    public: void fun(); //x,y,k,l,m are accessible
};

class C: private B {
    public: int p;
    protected: int r;
    private: int s;
    public: void fun();//x, y, k, l, p, r, s are accessible
};
class D: public C {
    public: int u;
    protected: int v;
    private: int w;
    public: void fun();//p,r,u,v,w are accessible
    //x,y,z,k,k,l,m,s are inaccessible
};