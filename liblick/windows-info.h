/**
 * @file
 * @brief Determine information about the type of Windows installed
 */

#pragma once

enum WINDOWS_FAMILY {
    F_UNKNOWN,
    F_WINDOWS_9X,
    F_WINDOWS_NT,
    F_WINDOWS_VISTA,
};

enum WINDOWS_VERSION {
    V_UNKNOWN,
    V_WINDOWS_95,
    V_WINDOWS_98,
    V_WINDOWS_ME,
    V_WINDOWS_2000,
    V_WINDOWS_XP,
    V_WINDOWS_VISTA,
    V_WINDOWS_7,
    V_WINDOWS_8,
    V_WINDOWS_8_1,
    V_WINDOWS_10,
};

enum WINDOWS_ARCHITECTURE {
    A_UNKNOWN,
    A_WINDOWS_X86,
    A_WINDOWS_X86_64,
};

enum IS_ADMIN {
    ADMIN_UNKNOWN,
    ADMIN_YES,
    ADMIN_NO,
};

enum IS_BIOS {
    BIOS_UNKNOWN,
    BIOS_BIOS,
    BIOS_UEFI,
};

/**
 * @brief determines the name of the given windows version
 * @param v the windows version
 * @return the name of the version. Do not free this value
 */
char *version_name(enum WINDOWS_VERSION v);
/**
 * @brief determines the name of the given windows family
 * @param f the windows family
 * @return the name of the family. Do not free this value
 */
char *family_name(enum WINDOWS_FAMILY f);
/**
 * @brief determines the name of the given architecture
 * @param a the architecture
 * @return the name of the architecture. Do not free this value
 */
char *arch_name(enum WINDOWS_ARCHITECTURE a);
/**
 * @brief determines the name of the given BIOS type
 * @param b the BIOS type
 * @return the name of the BIOS type. Do not free this value
 */
char *bios_name(enum IS_BIOS b);

/**
 * @brief relevant info about the system
 */
typedef struct {
    /// the windows version family
    enum WINDOWS_FAMILY family;
    /// name of the windows version family
    char *family_name;
    /// the windows version
    enum WINDOWS_VERSION version;
    /// name of the windows version
    char *version_name;
    /// the architecture
    enum WINDOWS_ARCHITECTURE arch;
    /// name of the architecture
    char *arch_name;
    /// the type of BIOS
    enum IS_BIOS is_bios;
    /// name of the type of BIOS
    char *bios_name;
    /// does the process have administrator privileges
    enum IS_ADMIN is_admin;
} win_info_t;

/**
 * @brief returns info about the system
 * @return info about the system
 */
win_info_t get_windows_version_info();
