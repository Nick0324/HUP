#################################################################################
# USER AREA: Place here directories, source/object files, include pathes        #
#################################################################################
#                                                                               #
#  Sample contents:                                                             #
#                                                                               #
#  MOD_NAME           = <relative_folder_path>\\<app_folder>                    #
#  SET_FILE_EXT       = std                                                     #
#  SRC_FILES          = $(SRC_DIR)/Application.c                                #
#  SRC_FILES          =                                                         #
#  ASM_FILES          =                                                         #
#  INC_PATHS          = -I$(INC_DIR) -I$(INC_DIR_MOD)                           #
#                                                                               #
#################################################################################


MOD_NAME           = \\20_BSW\\IoStck\\IoDrv\\Dio
#--------------------------------------------------------------------------------
SET_FILE_EXT       = std

SRC_FILES           = $(SRC_DIR)/Dio.c 

ASM_FILES           = 
PRE_BUILT_OBJ_FILES = 
PRE_BUILT_LIB_FILES =

INC_PATHS          = -I$(INC_DIR) -I$(INC_DIR_MOD)

