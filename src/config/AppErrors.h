#ifndef APPERRORS_H
#define APPERRORS_H

#include "include/String.h"

class AppErrors {
	public:
		static const String wrongCommandError;
		static const String invalidUsernameError;
		static const String invalidPasswordError;
		static const String invalidEmailError;
		static const String invalidDestinationError;
		static const String invalidImageExtensionError;
		static const String invalidImageNameError;
		static const String noDestinationFoundError;
		static const String invalidDatePeriod;
		static const String invalidGradeError;
		static const String invalidCommentError;
		static const String userAlreadyExists;
		static const String noUserFoundError;
		static const String cannotMakeYourselfFriend;
};

#endif