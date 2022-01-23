#include "designpatterns.h"
int main() {
	CreationalPattern::ObserverPattern::User aby(0);
	CreationalPattern::ObserverPattern::User someChannel(1);
	CreationalPattern::ObserverPattern::User someChannelTwo(2);
	CreationalPattern::ObserverPattern::YoutubeChannel bilgisayarkavramlari;

	bilgisayarkavramlari.registerObserver(&aby);
	bilgisayarkavramlari.registerObserver(&someChannel);
	bilgisayarkavramlari.registerObserver(&someChannelTwo);

	bilgisayarkavramlari.upload("Neler yaptýk neden yoktuk sizleri özledik");
	bilgisayarkavramlari.removeObserver(&aby);
	bilgisayarkavramlari.upload("Gelecekte ne olacak? Tam hýzla Türkçe video paylaþmaya devam edeceðiz.");
	bilgisayarkavramlari.removeObserver(&someChannel);
	bilgisayarkavramlari.removeObserver(&someChannelTwo);
}