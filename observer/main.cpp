#include "designpatterns.h"
int main() {
	CreationalPattern::ObserverPattern::User aby(0);
	CreationalPattern::ObserverPattern::User someChannel(1);
	CreationalPattern::ObserverPattern::User someChannelTwo(2);
	CreationalPattern::ObserverPattern::YoutubeChannel bilgisayarkavramlari;

	bilgisayarkavramlari.registerObserver(&aby);
	bilgisayarkavramlari.registerObserver(&someChannel);
	bilgisayarkavramlari.registerObserver(&someChannelTwo);

	bilgisayarkavramlari.upload("Neler yapt�k neden yoktuk sizleri �zledik");
	bilgisayarkavramlari.removeObserver(&aby);
	bilgisayarkavramlari.upload("Gelecekte ne olacak? Tam h�zla T�rk�e video payla�maya devam edece�iz.");
	bilgisayarkavramlari.removeObserver(&someChannel);
	bilgisayarkavramlari.removeObserver(&someChannelTwo);
}