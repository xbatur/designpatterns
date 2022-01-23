#ifndef DESIGN_PATTERNS_H
#define DESIGN_PATTERNS_H
#include <vector>
#include <string>
#include <iostream>
namespace CreationalPattern {
	namespace ObserverPattern {
		enum notiftyType {
			uploadVideo,
		};
		//Base Class, Interface
		class Observer {
		public:
			virtual void uploadVideo(std::string videoName) = 0;
			virtual int getUserID() = 0;
		};
		//Base Class, Interface
        class Subject {
        public:
            virtual void registerObserver(Observer* observer) = 0;
            virtual void removeObserver(Observer* observer) = 0;
			virtual void notifyObservers(notiftyType type, std::string message = "default") = 0;
        };

		class YoutubeChannel : public Subject{
		public:
			virtual void registerObserver(Observer* observer) override {
				observers.push_back(observer);
				std::cout << "===============================\n";
				std::cout << "UserID: " << observer->getUserID() << " is subscribed!. \n";
			};
			virtual void removeObserver(Observer* observer) override {
					std::cout << "===============================\n";
				std::cout << observer->getUserID() << " is unsubscribing. \n";
				auto iterator = std::find(observers.begin(), observers.end(), observer);
				if (iterator != observers.end()) {
					observers.erase(iterator); 
					std::cout << "Unsubscribed. \n";
				}
				else {
					std::cout << "Iterator error occured. \n";
				}
			};
			virtual void notifyObservers(notiftyType type, std::string message = "default") override {
				switch (type) {
				case uploadVideo:
					for (Observer* observer : observers) { // notify all observers
						observer->uploadVideo(message);
					}
					break;
				}
			};
			void upload(std::string videoName) {
				notifyObservers(uploadVideo, videoName);
			};
		private:
			std::vector<Observer*> observers;
		};
		class User : public Observer{
		public:
			//Constructor method
			User(int id) {
				userID = id;
			}
			virtual void uploadVideo(std::string videoName) override{
				std::cout << "===============================\n";
				std::cout << "Notified User: " << userID << "\nNotifyType:" << "Video Upload\n" << videoName << '\n';
			};
			virtual int getUserID() override{
				return userID;
			}
		private:
			int userID;
		};
	}
}
#endif
