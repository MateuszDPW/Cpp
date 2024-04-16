/**/

int* ptr;
int value = 6;
int* ptr = &value;

//unique_ptr jest inteligentnym wskaźnikiem, który gwarantuje że tylko jeden wskaźnik może zarządzać danym zasobem w danym momencie

#include <memory>
std::unique_ptr<int> 

//shared_ptr umożliwia współdzielenie zarządzanego zasobu przez wiele wskaźników poprzez śledzenie liczby referencji
//współdzielenie zasobów, automatyczne zwalnianie pamięci, bezpieczeństwo


std::shared_ptr<int> ptr1 = std::make_shared<int>(5);
std::shared_ptr<int> ptr2 = ptr1;

//weak_ptr jest używany do obserwowania shared_ptr bez zwiąkszania licznika referencji, jest przydatny do zapobiegania cyklicznym zależnościom
std::shared_ptr<int> ptr1 = std::make_shared<int>(5);
std::weak_ptr<int> ptr2 = ptr1;
