#include <iostream>
#include <vector>

using namespace std;


template<typename T,typename fun_obj>
auto own_search( typename std::vector<T,std::allocator<T>> ::iterator
                    const& left,
                typename std::vector<T,std::allocator<T>> ::iterator
                    const& right,
                T const& target,
                fun_obj const& compare_ ){
    if(left > right){
        printf("out\n");
        if(compare_((*left),(*right)) > 0){
            return std::make_pair(left,right-2);
        }else{
            return std::make_pair(left+2,right);
        }
    }
    auto middle = left + ((right - left)/2);

    int flag = compare_((*middle), target);
    if(flag == 0){
        printf("find\n");
        return make_pair(middle,middle);
    }else if(flag > 1){
        return own_search(left,middle,target,compare_);
    }else{
        return own_search(middle,right,target,compare_);
    }
}

template<typename T>
auto own_search( typename std::vector<T,std::allocator<T>> ::iterator
                    const& left,
                typename std::vector<T,std::allocator<T>> ::iterator
                    const& right,
                T const& target
        ){
    return own_search(left,right,target,[](T const& x, T const &y)->int{
                                                return x-y;
                                               });
}

struct Point{
    int x;
    int y;
    Point(int const& a,int const&b):x(a),y(b){ }
};


int main(void)
{
    /* vector<Point> s = {{2,3},{3,1},{3,3},{4 ,5}, {6,7}}; */
    /* Point tag(3,1); */
    /* printf("search begin\n"); */
    /* auto&& x = own_search(s.begin(), s.end(), tag, [](auto const& a,auto const& b)->int{ */
    /*                                                     printf("cmp\n"); */
    /*                                                     int i = (a.x - b.x); */
    /*                                                     if(i == 0){ */
    /*                                                         return a.y - b.y; */
    /*                                                     } */
    /*                                                     return i; */
    /*                                                 }); */

    /* printf("index of left_near %ld  index of right_near %ld\n",(x.first - s.begin()),(x.second - s.begin())); */

    vector<int> v = {1,3,5 ,8,13,43};   

    printf("search begin\n");
    auto&& y = own_search(v.begin(), v.end(), 5);
    /* auto&& y = own_search(v.begin(), v.end(), 5, [](auto const& x,auto const& y)->int { */
    /*                                                     printf("cmp\n"); */
    /*                                                     return (x-y); */ 
    /*                                                 }); */
    /* auto&& x = own_search(v.begin(), v.end()-1, 5); */
    /* error */
    printf("%d %d\n",*y.first,*y.second);
    printf("%ld %ld\n",(y.first - v.begin()),(y.second - v.begin()));
    return 0;
}

