#ifndef LETTER_H_
#define LETTER_H_

#include <vector>
#include <iostream>

const int rows = 16;
const int columns = 8;

/*! \brief Klasa, ktora reprezentuje litere.
*
* \details Format 16x8 pixeli, rastrowe i same male litery.
*/
class Letter {
private:
	int id, next_id;
	char whatLetter;
	std::vector< std::vector<int> > letter;

public:
	/*! \brief Konstruktor bezparametryczny.
	*/
	Letter() {}

	/*! \brief Konstruktor parametryczny.
	*/
	Letter(std::vector< std::vector<int> > t) : letter(t) {}

	/*! \brief Konstruktor kopiujacy.
	*/
	Letter(const Letter& l) {
		id = l.id; next_id = l.next_id; whatLetter = l.whatLetter;
		letter = l.letter;
	}

	// gettery
	int GetId() { return id; }
	char GetLetter() { return whatLetter; }
	std::vector< std::vector<int> > Get() { return letter; }
	void clear() { letter.clear(); }

	friend std::istream& operator >> (std::istream& in, Letter& l);
	friend std::ostream& operator << (std::ostream& out, const Letter& l);
};

inline std::istream& operator >> (std::istream& input, Letter& l) {
	int temp;
	input >> l.id >> l.whatLetter >> l.next_id >> temp >> temp >> temp;
	std::vector<int> row;  // reserve enough memory
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			input >> temp;
			row.push_back(temp);
		}
		l.letter.push_back(row);
		row.clear();
	}

	return input;
}

inline std::ostream& operator << (std::ostream& out, const Letter& l) {
	out << "Id: " << l.id << "\tletter: " << l.whatLetter << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			out << l.letter[i][j] << " ";
		}
		out << std::endl;
	}

	return out;
}

#endif  // LETTER_H_