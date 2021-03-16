template<typename T>
void travelRoute(Route*const ptr_route,T&& lambda){
    if(ptr_route->next_route != nullptr){
        lambda();
        travelRoute(ptr_route->next_route,std::forward<T>(lambda));
        return ;
    }
    
    for (auto i = ptr_route->next_station->out_station.begin(); i != ptr_route->next_station->out_station.cend(); ++i) {
        if((*i)->bus_no == ptr_route->bus_no){
            ptr_route->next_route = *i;
            lambda();
            travelRoute(ptr_route->next_route,std::forward<T>(lambda));
            return;
        }
    }

}
