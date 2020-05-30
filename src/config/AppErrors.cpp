#include "AppErrors.h"
#include "AppConfig.h"

const String AppErrors::wrongCommandError = "Error: invalid command!";
const String AppErrors::invalidUsernameError = "Error: the username you entered is not in the correct format!";
const String AppErrors::invalidPasswordError = "Error: the password you entered is too short!";;
const String AppErrors::invalidEmailError = "Error: incorrect email format!";;
const String AppErrors::invalidDestinationError = "Error: the destination you entered contains characters that are not allowed!";
const String AppErrors::invalidImageExtensionError = "Error: the format of the image you wanted to add is supported!";
const String AppErrors::invalidImageNameError = "Error: the image name you entered contains characters that are not allowed!";
const String AppErrors::noDestinationFoundError = "Error: no destination found for the criteria you entered!";
const String AppErrors::invalidDatePeriod = "Error: invalid date period!";
const String AppErrors::invalidGradeError = String{ "Error: grade must be between " } + String::toString(AppConfig::gradeBoundaries[0]) + " and " + String::toString(AppConfig::gradeBoundaries[1]) +"!";
const String AppErrors::invalidCommentError = "Error: the comment you wanted to make contains characters that are not allowed or words that are offensive!";
const String AppErrors::userAlreadyExists = "Error: a user with this username already exists!";
const String AppErrors::noUserFoundError = "Error: no user was found for the useranme you entered!";
const String AppErrors::cannotMakeYourselfFriend = "Error: cannot make yourself a friend :(";
const String AppErrors::destinationNotVisitedError = "Error: you haven't visited ";