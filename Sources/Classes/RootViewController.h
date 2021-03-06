/* 
 * Copyright (C) 2010  James Stapleton
 *
 * This file is part of Iphone PasswordMaker.
 *
 * Iphone PasswordMaker is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Iphone PasswordMaker is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with Iphone PasswordMaker.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include "hash_type_enum.h"
@class Hasher ;

@interface RootViewController : UITableViewController<UITextFieldDelegate> {
	UITextField* masterPassword ;
	UITextField* inputURL ;
	// UISlider* length ;
	UITextField* passLength ;
	UITextField* username ;
	UITextField* modifier ;
	//UITextField* characters ;
	UITextField* prefix ;
	UITextField* suffix ;
	UITextView* generatedPassword ;
	NSMutableArray* tableCells;
	Hasher* hasher ;
	BOOL masterPasswordHashMatches ;
	NSMutableArray* favorites;
}
- (id) initWithHasher:(Hasher*)hashObj ;

// private
- (UITextField*) allocTextField:(NSString*)txt ;
- (UITextField*) allocTextField:(NSString*)txt isPassword:(BOOL)isPass ;
- (UITextField*) allocTextField:(NSString*)txt keyboardType:(UIKeyboardType)kbt ;
- (UITextView*) allocTextView:(NSString*)txt readonly:(BOOL)readonly ;

- (UITableViewCell*) makeCellWithLabel:(NSString*)str
						andContentView:(UIView*)cview ;

- (UITableViewCell*) makeCellWithLabel:(NSString*)str
							accessType:(UITableViewCellAccessoryType)acc ;

- (UITableViewCell*) makeInputUrlCellWithLabel:(NSString*)str
								WithTextField:(UITextField*)fieldValue accessType:(UITableViewCellAccessoryType)acc ;

- (UITableViewCell*) cellForRow:(int)row ;

- (NSString*) getCharacterSelDesc ;

- (void) shouldSaveSettings:(UIApplication *)application ;

- (IBAction) updateGeneratePassword ;
+ (NSString*) LeetEnumToString:(enum leetType)lt WithLevel:(NSInteger)level;

- (void) initCells;

- (IBAction) copyPasswordClicked;

- (IBAction) updateFieldsFromHasher ;

- (void) update_password_fields_color ;

- (void) set_proper_keyboard;

@end
