#ifndef CARTA_H
#define CARTA_H
#include<string>
class Carta
{
	public:
			static const string ORO="Oro";
			static const string BASTONI="Bastoni";
			static const string SPADE="Spade";
			static const string COPPE="Coppe";
		Carta();
		Carta( unsigned char val,string figu);
		const string GetCard();
		string GetSeme();
		unsigned char GetValore();
		bool compara(Carta b);
	private:
		string seme;
		unsigned char numero; 
};

#endif
