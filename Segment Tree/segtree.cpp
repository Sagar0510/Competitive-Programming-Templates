
struct node
{
    //**1
    ll sum = 0;
    // use more variables according to the things you want from each node in segtree
    // these default values should be identity_element
    node(){}
    node(ll val){
        //**2
        sum = val;
        // constructor, what each value in LEAF should store
    }
    void merge(const node &l,const node &r){ 
        //**3
        sum = l.sum + r.sum;
        //how would you build up the value of each node from the children
        // if we wanted the maximum, then we would do
        // like sum = max(l.sum,r.sum) where l and r are left and right children
    }
};

struct update
{
    // **4
    ll v = 0; 
    // use more variables if you want more things to update, for eg intead of v, we might want to add a sequence or AP on the range
    // these default values should be identity_transformation
    update(){}
    update(ll val){
        //**5
        v = val;
        //initialising update values
    }
    // combine the current update with the other update (see keynotes)
    void combine(update &other,const int32_t &tl,const int32_t &tr){
        //**6
        v += other.v;
        // you can be sure that the "other" is newer than current
        // this where you update the upd value of the lazy man
    }
    // store the correct information in the node x
    void apply(node &x,const int32_t &tl,const int32_t &tr){
        //**7
        x.sum += (tr - tl + 1) * v;
        // each value in a node gets correct value of pushdown
    }
};

template<typename node,typename update>
struct segtree
{
    ll len;
    vector<node> t;
    vector<update> u;
    vector<bool> lazy;
    node identity_element;
    update identity_transformation;
    segtree(ll l){
        len = l;
        t.resize(4 * len);
        u.resize(4 * len);
        lazy.resize(4 * len);
        identity_element = node();
        identity_transformation = update();
    }
 
    void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr){
        if(!lazy[v]) return;
        int32_t tm = (tl + tr) >> 1;
        apply(v<<1,tl,tm,u[v]);
        apply(v<<1|1,tm+1,tr,u[v]);
        u[v] = identity_transformation;
        lazy[v] = 0;
    }
 
    void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd){
        if(tl != tr){
            lazy[v] = 1;
            u[v].combine(upd,tl,tr);
        }
        upd.apply(t[v],tl,tr);
    }
 
    template<typename T>
    void build(const T &arr,const int32_t &v, const int32_t &tl, const int32_t &tr){
        if(tl == tr){
            t[v] = arr[tl];
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr,v<<1,tl,tm);
        build(arr,v<<1|1,tm+1,tr);
        t[v].merge(t[v<<1],t[v<<1|1]);
    }
 
    node query(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r){
        if(l > tr || r < tl){
            return identity_element;
        }
        if(tl >= l && tr <= r){
            return t[v];
        }
        pushdown(v,tl,tr);
        int32_t tm = (tl + tr) >> 1;
        node a = query(v<<1,tl,tm,l,r),b = query(v<<1|1,tm+1,tr,l,r),ans;
        ans.merge(a,b);
        return ans;
    }
 
    // rupd = range update
    void rupd(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,const update &upd){
        if(l > tr || r < tl){
            return;
        }
        if(tl >= l && tr <= r){
            apply(v,tl,tr,upd);
            return;
        }
        pushdown(v,tl,tr);
        int32_t tm = (tl + tr) >> 1;
        rupd(v<<1,tl,tm,l,r,upd);
        rupd(v<<1|1,tm+1,tr,l,r,upd);
        t[v].merge(t[v<<1],t[v<<1|1]);
    }
 
    public:
    template<typename T>
    void build(const T &arr){
        build(arr,1,0,len-1);
    }
    node query(const int32_t &l,const int32_t &r){
        return query(1,0,len-1,l,r);
    }
    void rupd(const int32_t &l,const int32_t &r,const update &upd){
        rupd(1,0,len-1,l,r,upd);
    }
};

