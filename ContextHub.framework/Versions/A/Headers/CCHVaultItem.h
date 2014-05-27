//
//  CCBVaultItem.h
//  ContextHub
//
//  Created by Kevin Lee on 11/1/13.
//  Copyright (c) 2013 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 The CCBVaultItem protocol can be used if you want to easily save your objects to the Vault.
 
 @note We recommend creating an initWithDictionary: method for your class so that you can easily initialize your objects
 from the API responses.  If you set the valutInfo diction to the value of the vault_info key in the response
 it will be easy to update and delete the data in the future.
*/
@protocol CCHVaultItem <NSObject>

/**
 the name of the container that you want to store your object in.  This is usually the class name. ie Employee
 */
- (NSString *)containerName;

/**
 your object as a dictionary.
 */
- (NSDictionary *)asDictionary;


@optional
/** 
 maintaining the vault info will allow you to easily update and delete data that is saved in the Vault
 */
@property (nonatomic, strong) NSDictionary *vaultInfo;
@end
