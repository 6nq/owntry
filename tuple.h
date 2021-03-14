#include <tuple>
#ifndef TUPLE_H
#define TUPLE_H

//创建n个索引
template<std::size_t... arg>
struct integer_sequence {
    /* static constexpr std::size_t value[ sizeof...(arg) ] = {arg...}; */ 
    using type = integer_sequence;
};
template<std::size_t N,std::size_t... arg>
struct make_index_sequence_helper {
    using type = typename make_index_sequence_helper<N-1,N-1,arg...>::type;
};
template<std::size_t... arg>
struct make_index_sequence_helper<0,arg...> {
    using type = integer_sequence<arg...>;
};
template<std::size_t N>
using make_index_sequence_own = typename make_index_sequence_helper<N>::type;

//转发tuple参数包
template<class F,class Tuple,std::size_t... I>
constexpr decltype(auto) apply_impl_own(F&& f,Tuple&& t,integer_sequence<I...>){
    return f(get<I>(std::forward<Tuple>(t))...);
}
template<class F,class Tuple>
constexpr decltype(auto) apply_own(F&& f,Tuple&& t){
    return apply_impl_own(std::forward<F>(f),std::forward<Tuple>(t),make_index_sequence_own<std::tuple_size_v<std::remove_reference_t<Tuple>>>{});
}


#endif /* TUPLE_H */
