#include <iostream>
using std::cout;
using std::endl;
using std::cin;

  enum class Album
{
	NONE,
	DARE_TO_BE_STUPID,
  POLKA_PARTY,
  EVEN_WORSE,
  OFF_THE_DEEP_END,
  BAD_HAIR_DAY,
  RUNNING_WITH_SCISSORS,
  MANDATORY_FUN
};


// Prototypes
Album getWantedAlbum();
int getAlbumPrice(Album album);
int inputPennies();
int change;

// Pulling the whole program together
int main()
{
  // Declaring my variables
  Album wanted_album = getWantedAlbum();
  int wanted_album_price_cents = getAlbumPrice(wanted_album);
  int user_payment_amount_cents = inputPennies();

  // Printing a message if no album is selected
  if (Album::NONE == wanted_album){
    cout << "No album selected; Quitting!" << endl;
  }
  // Using this else block to stop the program from continuing
  else {
    // If the user enters the exact amount of change in cents
    if (user_payment_amount_cents == wanted_album_price_cents){
      cout << "Here is your album. Thank you for choosing this program." << endl;
    }
    // If the user enters more than the amount owed
    else if (user_payment_amount_cents > wanted_album_price_cents){
      change = user_payment_amount_cents- wanted_album_price_cents;
      cout << "Here is your album, along with your change of " << change << " cents. Thank you for choosing this program." << endl;
    }
    // If the user enters a value less than the price
    else {
      cout << "We're not running a charity." << endl;
    }
  }

	return 0;
}


Album getWantedAlbum()
{
  // Declaring my variables
  Album user_album_selection;
  int input;
  // Printing the menu
  cout << "*** The Smallest Store Evar ***" << endl;
  cout << "Welcome to our purchase system!" << endl;
  cout << "Which album would you like to purchase?" << endl;
  cout << "1. Dare to Be Stupid: 999 cents" << endl;
  cout << "2. Polka Party: 899 cents" << endl;
  cout << "3. Even Worse: 899 cents" << endl;
  cout << "4. Off the Deep End: 799 cents" << endl;
  cout << "5. Bad Hair Day: 699 cents" << endl;
  cout << "6. Running With Scissors: 699 cents" << endl;
  cout << "7. Mandatory Fun: 599 cents" << endl;
// Asking the user what album they want to purchase
  cout << "==> ";
  cin >> input;
// Assigning user_album_selection to an album selection
  switch (input) {
    case 1:
      user_album_selection = Album::DARE_TO_BE_STUPID;
      break;
    case 2:
      user_album_selection = Album::POLKA_PARTY;
      break;
    case 3:
      user_album_selection = Album::EVEN_WORSE;
      break;
    case 4:
      user_album_selection = Album::OFF_THE_DEEP_END;
      break;
    case 5:
      user_album_selection = Album::BAD_HAIR_DAY;
      break;
    case 6:
      user_album_selection = Album::RUNNING_WITH_SCISSORS;
      break;
    case 7:
      user_album_selection = Album::MANDATORY_FUN;
      break;
    // If the user chooses an invalid album, we default it to none
    default:
      user_album_selection = Album::NONE;
  }
  return user_album_selection;
}

int getAlbumPrice(Album album)
{
  // Declaring my variables
  int price;

	// Getting the price of album
  switch (album) {
    case Album::DARE_TO_BE_STUPID:
      price = 999;
      break;
    case Album::POLKA_PARTY:
      price = 899;
      break;
    case Album::EVEN_WORSE:
      price = 899;
      break;
    case Album::OFF_THE_DEEP_END:
      price = 799;
      break;
    case Album::BAD_HAIR_DAY:
      price = 699;
      break;
    case Album::RUNNING_WITH_SCISSORS:
      price = 699;
      break;
    case Album::MANDATORY_FUN:
      price = 599;
      break;
    case Album::NONE:
      price = 0;
      break;
    // Using an exception to prevent possible errors
    default:
      throw std::runtime_error("getAlbumPrice() - Unhandled Album value!");
  }
  return price;
}

int inputPennies()
{
  // Declaring my variables
	int pennies;

  // Asking for user input in Pennies
  cout << "Please input the amount of pennies: " << endl;
  cin >> pennies;

  // Checking for a positive input
  if (pennies < 0) {
    cout << "This ain't no goddamn charity!" << endl;
    pennies = 0;
  }

  return pennies;
}
