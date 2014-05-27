//
//  CCBVaultService.h
//  ContextHub
//
//  Created by Kevin Lee on 10/7/13.
//  Copyright (c) 2013 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCHVaultItem.h"

#define kCarbonVaultErrorDomain @"com.chaione.carbon.vault.error"
/** 
 ContextHub Vault error codes.
 */
typedef NS_ENUM(NSInteger, CCBCarbonVaultErrorCode) {
    /**
     missing container error code.
     */
    CCBMissingContainerCode = 0
};

typedef void (^vaultCompletionBlock)(NSDictionary *carbonResponse, NSError *error);
typedef void (^vaultListingCompletionBlock)(NSArray *carbonResponses, NSError *error);

/**
 The shared CCBVaultSerivce should be used to persist data to the ContextHub Vault API.  This class provides methods for creating data in containers.
 You can think of a container as a bucket for common data.
 Once you persist data, you can retrieve it id.  You can also retrieve all data in a specific container.
 */
@interface CCHVaultService : NSObject


/**
 @returns the static shared instance of the the Vault Service
 */
+ (CCHVaultService *)sharedService;

/**
If you need to store data in the ContextHub Vault, you will create the data in a container.
 @param item the NSDictionary representation of the item you want to persist
 @param containerName the name of the container that will be used to store similar data
 @param completionBlock executed after the create operation has completed on the server.
 */
- (void)createItem:(NSDictionary *)item inContainer:(NSString *)containerName completion:(vaultCompletionBlock)completionBlock;

/** 
 If you need to store data AND resources in the ContextHub Vault, you will need to pass the data and an array of CCBVaultResource objects for the files that you want uploaded.
 @param item the NSDictionary representation of the item you want to persist.
 @param resources an array CCBVaultResource for the files that you want to upload.
 @param containerName the name of the container that will be used to store similar data.
 @param completionBlock executed after the create operation has completed on the server.
 */
- (void)createItem:(NSDictionary *)item withResources:(NSArray *) resources inContainer:(NSString *)containerName completion:(vaultCompletionBlock)completionBlock;

/** 
Used to retrieve the latest version of an item that is stored in the ContextHub Vault.
 @param item custom data item with vault id
 @param completionBlock executed when api request completes.
 */
- (void)getItem:(NSDictionary *)item completion:(vaultCompletionBlock)completionBlock;

/**
 Used to retrieve the latest version of an item that is stored in the ContextHub Vault.
 @param containerName name of the container for the items
 @param completionBlock executed when the api request completes.
 */
- (void)getItemsInContainer:(NSString *)containerName completion:(vaultListingCompletionBlock)completionBlock;

///**
// Used to retrieve a list of all containers that are stored in the ContextHub Vault.
// @param completionBlock excuted when api request completes.
// */
//- (void)getContainersWithCompletion:(vaultListingCompletionBlock)completionBlock;

/**
executes the vaultCompletionBlock passing in the dictionary and error.
 @param block a valut completeion block
 @param carbonResponse response dictionary from ContextHub vault api
 @param error NSError object.  can be nil.
 */
- (void)executeVaultCompletionBlock:(vaultCompletionBlock)block
            withCarbonResponse:(NSDictionary *)carbonResponse
                         error:(NSError *)error;

/**
 executes the vaultListingCompletionBlock passing in the dictionary and error.
 @param block a valut completeion block
 @param carbonResponse response dictionary from ContextHub vault api
 @param error NSError object.  can be nil.
 */
- (void)executeVaultListingCompletionBlock:(vaultListingCompletionBlock)block
                 withCarbonResponse:(NSDictionary *)carbonResponse
                              error:(NSError *)error;

/**
 updates the item
 @param item item to be updated;
 @param completionBlock vaultCompletionBlock
 */
- (void)updateItem:(NSDictionary *)item completion:(vaultCompletionBlock)completionBlock;

/**
 updates the item with associated file resources
 @param resources an array of CCBVaultResource objects for the files that will be associated.
 @param item item to be updated;
 @param completionBlock vaultCompletionBlock
 */
- (void)updateItem:(NSDictionary *)item withResources:(NSArray *)resources completion:(vaultCompletionBlock)completionBlock;

/**
 deletes the item
 @param item item to be deleted;
 @param completionBlock vaultCompletionBlock
 */
- (void)deleteItem:(NSDictionary *)item completion:(vaultCompletionBlock)completionBlock;

/**
 Save an object that implements the CCBVaultItem protocol in the ContextHub Vault.
 @param item the CCBVault item that you want to persist
 @param completionBlock executed after the create operation has completed on the server.
 */
- (void)createVaultItem:(id<CCHVaultItem>)item completion:(vaultCompletionBlock)completionBlock;

/**
 Update an object that implements the CCBVaultItem protocol in the ContextHub Vault.
 @warning Your object must have maintain the vaultInfo property.
 @param item the CCBVault item that you want to persist
 @param completionBlock executed after the create operation has completed on the server.
 */
- (void)updateVaultItem:(id<CCHVaultItem>)item completion:(vaultCompletionBlock)completionBlock;

/**
 Delete an object that implements the CCBVaultItem protocol from the ContextHub Vault.
 @warning Your object must have maintain the vaultInfo property.
 @param item the CCBVault item that you want to persist.
 @param completionBlock executed after the create operation has completed on the server.
 */
- (void)deleteVaultItem:(id<CCHVaultItem>)item completion:(vaultCompletionBlock)completionBlock;
@end
