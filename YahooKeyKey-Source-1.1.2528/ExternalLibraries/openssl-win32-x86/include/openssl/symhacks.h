/* ====================================================================
 * Copyright (c) 1999 The OpenSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"
 *
 * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    openssl-core@openssl.org.
 *
 * 5. Products derived from this software may not be called "OpenSSL"
 *    nor may "OpenSSL" appear in their names without prior written
 *    permission of the OpenSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This product includes cryptographic software written by Eric Young
 * (eay@cryptsoft.com).  This product includes software written by Tim
 * Hudson (tjh@cryptsoft.com).
 *
 */

#ifndef HEADER_SYMHACKS_H
#define HEADER_SYMHACKS_H

#include <openssl/e_os2.h>

/* Hacks to solve the problem with linkers incapable of handling very long
   symbol names.  In the case of VMS, the limit is 31 characters on VMS for
   VAX. */
#ifdef OPENSSL_SYS_VMS

/* Hack a long name in crypto/ex_data.c */
#undef CRYPTO_get_ex_data_implementation
#define CRYPTO_get_ex_data_implementation CRYPTO_get_ex_data_impl
#undef CRYPTO_set_ex_data_implementation
#define CRYPTO_set_ex_data_implementation CRYPTO_set_ex_data_impl

/* Hack a long name in crypto/asn1/a_mbstr.c */
#undef ASN1_STRING_set_default_mask_asc
#define ASN1_STRING_set_default_mask_asc ASN1_STRING_set_def_mask_asc

#if 0 /* No longer needed, since safestack macro magic does the job */
/* Hack the names created with DECLARE_ASN1_SET_OF(PKCS7_SIGNER_INFO) */
#undef i2d_ASN1_SET_OF_PKCS7_SIGNER_INFO
#define i2d_ASN1_SET_OF_PKCS7_SIGNER_INFO i2d_ASN1_SET_OF_PKCS7_SIGINF
#undef d2i_ASN1_SET_OF_PKCS7_SIGNER_INFO
#define d2i_ASN1_SET_OF_PKCS7_SIGNER_INFO d2i_ASN1_SET_OF_PKCS7_SIGINF
#endif

#if 0 /* No longer needed, since safestack macro magic does the job */
/* Hack the names created with DECLARE_ASN1_SET_OF(PKCS7_RECIP_INFO) */
#undef i2d_ASN1_SET_OF_PKCS7_RECIP_INFO
#define i2d_ASN1_SET_OF_PKCS7_RECIP_INFO i2d_ASN1_SET_OF_PKCS7_RECINF
#undef d2i_ASN1_SET_OF_PKCS7_RECIP_INFO
#define d2i_ASN1_SET_OF_PKCS7_RECIP_INFO d2i_ASN1_SET_OF_PKCS7_RECINF
#endif

#if 0 /* No longer needed, since safestack macro magic does the job */
/* Hack the names created with DECLARE_ASN1_SET_OF(ACCESS_DESCRIPTION) */
#undef i2d_ASN1_SET_OF_ACCESS_DESCRIPTION
#define i2d_ASN1_SET_OF_ACCESS_DESCRIPTION i2d_ASN1_SET_OF_ACC_DESC
#undef d2i_ASN1_SET_OF_ACCESS_DESCRIPTION
#define d2i_ASN1_SET_OF_ACCESS_DESCRIPTION d2i_ASN1_SET_OF_ACC_DESC
#endif

/* Hack the names created with DECLARE_PEM_rw(NETSCAPE_CERT_SEQUENCE) */
#undef PEM_read_NETSCAPE_CERT_SEQUENCE
#define PEM_read_NETSCAPE_CERT_SEQUENCE PEM_read_NS_CERT_SEQ
#undef PEM_write_NETSCAPE_CERT_SEQUENCE
#define PEM_write_NETSCAPE_CERT_SEQUENCE PEM_write_NS_CERT_SEQ
#undef PEM_read_bio_NETSCAPE_CERT_SEQUENCE
#define PEM_read_bio_NETSCAPE_CERT_SEQUENCE PEM_read_bio_NS_CERT_SEQ
#undef PEM_write_bio_NETSCAPE_CERT_SEQUENCE
#define PEM_write_bio_NETSCAPE_CERT_SEQUENCE PEM_write_bio_NS_CERT_SEQ
#undef PEM_write_cb_bio_NETSCAPE_CERT_SEQUENCE
#define PEM_write_cb_bio_NETSCAPE_CERT_SEQUENCE PEM_write_cb_bio_NS_CERT_SEQ

/* Hack the names created with DECLARE_PEM_rw(PKCS8_PRIV_KEY_INFO) */
#undef PEM_read_PKCS8_PRIV_KEY_INFO
#define PEM_read_PKCS8_PRIV_KEY_INFO PEM_read_P8_PRIV_KEY_INFO
#undef PEM_write_PKCS8_PRIV_KEY_INFO
#define PEM_write_PKCS8_PRIV_KEY_INFO PEM_write_P8_PRIV_KEY_INFO
#undef PEM_read_bio_PKCS8_PRIV_KEY_INFO
#define PEM_read_bio_PKCS8_PRIV_KEY_INFO PEM_read_bio_P8_PRIV_KEY_INFO
#undef PEM_write_bio_PKCS8_PRIV_KEY_INFO
#define PEM_write_bio_PKCS8_PRIV_KEY_INFO PEM_write_bio_P8_PRIV_KEY_INFO
#undef PEM_write_cb_bio_PKCS8_PRIV_KEY_INFO
#define PEM_write_cb_bio_PKCS8_PRIV_KEY_INFO PEM_wrt_cb_bio_P8_PRIV_KEY_INFO

/* Hack other PEM names */
#undef PEM_write_bio_PKCS8PrivateKey_nid
#define PEM_write_bio_PKCS8PrivateKey_nid PEM_write_bio_PKCS8PrivKey_nid

/* Hack some long X509 names */
#undef X509_REVOKED_get_ext_by_critical
#define X509_REVOKED_get_ext_by_critical X509_REVOKED_get_ext_by_critic
#undef X509_policy_tree_get0_user_policies
#define X509_policy_tree_get0_user_policies X509_pcy_tree_get0_usr_policies
#undef X509_policy_node_get0_qualifiers
#define X509_policy_node_get0_qualifiers X509_pcy_node_get0_qualifiers
#undef X509_STORE_CTX_get_explicit_policy
#define X509_STORE_CTX_get_explicit_policy X509_STORE_CTX_get_expl_policy

/* Hack some long CRYPTO names */
#undef CRYPTO_set_dynlock_destroy_callback
#define CRYPTO_set_dynlock_destroy_callback CRYPTO_set_dynlock_destroy_cb
#undef CRYPTO_set_dynlock_create_callback
#define CRYPTO_set_dynlock_create_callback CRYPTO_set_dynlock_create_cb
#undef CRYPTO_set_dynlock_lock_callback
#define CRYPTO_set_dynlock_lock_callback CRYPTO_set_dynlock_lock_cb
#undef CRYPTO_get_dynlock_lock_callback
#define CRYPTO_get_dynlock_lock_callback CRYPTO_get_dynlock_lock_cb
#undef CRYPTO_get_dynlock_destroy_callback
#define CRYPTO_get_dynlock_destroy_callback CRYPTO_get_dynlock_destroy_cb
#undef CRYPTO_get_dynlock_create_callback
#define CRYPTO_get_dynlock_create_callback CRYPTO_get_dynlock_create_cb
#undef CRYPTO_set_locked_mem_ex_functions
#define CRYPTO_set_locked_mem_ex_functions CRYPTO_set_locked_mem_ex_funcs
#undef CRYPTO_get_locked_mem_ex_functions
#define CRYPTO_get_locked_mem_ex_functions CRYPTO_get_locked_mem_ex_funcs

/* Hack some long SSL names */
#undef SSL_CTX_set_default_verify_paths
#define SSL_CTX_set_default_verify_paths SSL_CTX_set_def_verify_paths
#undef SSL_get_ex_data_X509_STORE_CTX_idx
#define SSL_get_ex_data_X509_STORE_CTX_idx SSL_get_ex_d_X509_STORE_CTX_idx
#undef SSL_add_file_cert_subjects_to_stack
#define SSL_add_file_cert_subjects_to_stack SSL_add_file_cert_subjs_to_stk
#undef SSL_add_dir_cert_subjects_to_stack
#define SSL_add_dir_cert_subjects_to_stack SSL_add_dir_cert_subjs_to_stk
#undef SSL_CTX_use_certificate_chain_file
#define SSL_CTX_use_certificate_chain_file SSL_CTX_use_cert_chain_file
#undef SSL_CTX_set_cert_verify_callback
#define SSL_CTX_set_cert_verify_callback SSL_CTX_set_cert_verify_cb
#undef SSL_CTX_set_default_passwd_cb_userdata
#define SSL_CTX_set_default_passwd_cb_userdata SSL_CTX_set_def_passwd_cb_ud
#undef SSL_COMP_get_compression_methods
#define SSL_COMP_get_compression_methods SSL_COMP_get_compress_methods

/* Hack some long ENGINE names */
#undef ENGINE_get_default_BN_mod_exp_crt
#define ENGINE_get_default_BN_mod_exp_crt ENGINE_get_def_BN_mod_exp_crt
#undef ENGINE_set_default_BN_mod_exp_crt
#define ENGINE_set_default_BN_mod_exp_crt ENGINE_set_def_BN_mod_exp_crt
#undef ENGINE_set_load_privkey_function
#define ENGINE_set_load_privkey_function ENGINE_set_load_privkey_fn
#undef ENGINE_get_load_privkey_function
#define ENGINE_get_load_privkey_function ENGINE_get_load_privkey_fn

/* Hack some long OCSP names */
#undef OCSP_REQUEST_get_ext_by_critical
#define OCSP_REQUEST_get_ext_by_critical OCSP_REQUEST_get_ext_by_crit
#undef OCSP_BASICRESP_get_ext_by_critical
#define OCSP_BASICRESP_get_ext_by_critical OCSP_BASICRESP_get_ext_by_crit
#undef OCSP_SINGLERESP_get_ext_by_critical
#define OCSP_SINGLERESP_get_ext_by_critical OCSP_SINGLERESP_get_ext_by_crit

/* Hack some long DES names */
#undef _ossl_old_des_ede3_cfb64_encrypt
#define _ossl_old_des_ede3_cfb64_encrypt _ossl_odes_ede3_cfb64_encrypt
#undef _ossl_old_des_ede3_ofb64_encrypt
#define _ossl_old_des_ede3_ofb64_encrypt _ossl_odes_ede3_ofb64_encrypt

/* Hack some long EVP names */
#undef OPENSSL_add_all_algorithms_noconf
#define OPENSSL_add_all_algorithms_noconf OPENSSL_add_all_algo_noconf
#undef OPENSSL_add_all_algorithms_conf
#define OPENSSL_add_all_algorithms_conf OPENSSL_add_all_algo_conf

/* Hack some long EC names */
#undef EC_GROUP_set_point_conversion_form
#define EC_GROUP_set_point_conversion_form EC_GROUP_set_point_conv_form
#undef EC_GROUP_get_point_conversion_form
#define EC_GROUP_get_point_conversion_form EC_GROUP_get_point_conv_form
#undef EC_GROUP_clear_free_all_extra_data
#define EC_GROUP_clear_free_all_extra_data EC_GROUP_clr_free_all_xtra_data
#undef EC_POINT_set_Jprojective_coordinates_GFp
#define EC_POINT_set_Jprojective_coordinates_GFp EC_POINT_set_Jproj_coords_GFp
#undef EC_POINT_get_Jprojective_coordinates_GFp
#define EC_POINT_get_Jprojective_coordinates_GFp EC_POINT_get_Jproj_coords_GFp
#undef EC_POINT_set_affine_coordinates_GFp
#define EC_POINT_set_affine_coordinates_GFp EC_POINT_set_affine_coords_GFp
#undef EC_POINT_get_affine_coordinates_GFp
#define EC_POINT_get_affine_coordinates_GFp EC_POINT_get_affine_coords_GFp
#undef EC_POINT_set_compressed_coordinates_GFp
#define EC_POINT_set_compressed_coordinates_GFp EC_POINT_set_compr_coords_GFp
#undef EC_POINT_set_affine_coordinates_GF2m
#define EC_POINT_set_affine_coordinates_GF2m EC_POINT_set_affine_coords_GF2m
#undef EC_POINT_get_affine_coordinates_GF2m
#define EC_POINT_get_affine_coordinates_GF2m EC_POINT_get_affine_coords_GF2m
#undef EC_POINT_set_compressed_coordinates_GF2m
#define EC_POINT_set_compressed_coordinates_GF2m EC_POINT_set_compr_coords_GF2m
#undef ec_GF2m_simple_group_clear_finish
#define ec_GF2m_simple_group_clear_finish ec_GF2m_simple_grp_clr_finish
#undef ec_GF2m_simple_group_check_discriminant
#define ec_GF2m_simple_group_check_discriminant ec_GF2m_simple_grp_chk_discrim
#undef ec_GF2m_simple_point_clear_finish
#define ec_GF2m_simple_point_clear_finish ec_GF2m_simple_pt_clr_finish
#undef ec_GF2m_simple_point_set_to_infinity
#define ec_GF2m_simple_point_set_to_infinity ec_GF2m_simple_pt_set_to_inf
#undef ec_GF2m_simple_points_make_affine
#define ec_GF2m_simple_points_make_affine ec_GF2m_simple_pts_make_affine
#undef ec_GF2m_simple_point_set_affine_coordinates
#define ec_GF2m_simple_point_set_affine_coordinates ec_GF2m_smp_pt_set_af_coords
#undef ec_GF2m_simple_point_get_affine_coordinates
#define ec_GF2m_simple_point_get_affine_coordinates ec_GF2m_smp_pt_get_af_coords
#undef ec_GF2m_simple_set_compressed_coordinates
#define ec_GF2m_simple_set_compressed_coordinates ec_GF2m_smp_set_compr_coords
#undef ec_GFp_simple_group_set_curve_GFp
#define ec_GFp_simple_group_set_curve_GFp ec_GFp_simple_grp_set_curve_GFp
#undef ec_GFp_simple_group_get_curve_GFp
#define ec_GFp_simple_group_get_curve_GFp ec_GFp_simple_grp_get_curve_GFp
#undef ec_GFp_simple_group_clear_finish
#define ec_GFp_simple_group_clear_finish ec_GFp_simple_grp_clear_finish
#undef ec_GFp_simple_group_set_generator
#define ec_GFp_simple_group_set_generator ec_GFp_simple_grp_set_generator
#undef ec_GFp_simple_group_get0_generator
#define ec_GFp_simple_group_get0_generator ec_GFp_simple_grp_gt0_generator
#undef ec_GFp_simple_group_get_cofactor
#define ec_GFp_simple_group_get_cofactor ec_GFp_simple_grp_get_cofactor
#undef ec_GFp_simple_point_clear_finish
#define ec_GFp_simple_point_clear_finish ec_GFp_simple_pt_clear_finish
#undef ec_GFp_simple_point_set_to_infinity
#define ec_GFp_simple_point_set_to_infinity ec_GFp_simple_pt_set_to_inf
#undef ec_GFp_simple_points_make_affine
#define ec_GFp_simple_points_make_affine ec_GFp_simple_pts_make_affine
#undef ec_GFp_simple_group_get_curve_GFp
#define ec_GFp_simple_group_get_curve_GFp ec_GFp_simple_grp_get_curve_GFp
#undef ec_GFp_simple_set_Jprojective_coordinates_GFp
#define ec_GFp_simple_set_Jprojective_coordinates_GFp \
  ec_GFp_smp_set_Jproj_coords_GFp
#undef ec_GFp_simple_get_Jprojective_coordinates_GFp
#define ec_GFp_simple_get_Jprojective_coordinates_GFp \
  ec_GFp_smp_get_Jproj_coords_GFp
#undef ec_GFp_simple_point_set_affine_coordinates_GFp
#define ec_GFp_simple_point_set_affine_coordinates_GFp \
  ec_GFp_smp_pt_set_af_coords_GFp
#undef ec_GFp_simple_point_get_affine_coordinates_GFp
#define ec_GFp_simple_point_get_affine_coordinates_GFp \
  ec_GFp_smp_pt_get_af_coords_GFp
#undef ec_GFp_simple_set_compressed_coordinates_GFp
#define ec_GFp_simple_set_compressed_coordinates_GFp \
  ec_GFp_smp_set_compr_coords_GFp
#undef ec_GFp_simple_point_set_affine_coordinates
#define ec_GFp_simple_point_set_affine_coordinates ec_GFp_smp_pt_set_af_coords
#undef ec_GFp_simple_point_get_affine_coordinates
#define ec_GFp_simple_point_get_affine_coordinates ec_GFp_smp_pt_get_af_coords
#undef ec_GFp_simple_set_compressed_coordinates
#define ec_GFp_simple_set_compressed_coordinates ec_GFp_smp_set_compr_coords
#undef ec_GFp_simple_group_check_discriminant
#define ec_GFp_simple_group_check_discriminant ec_GFp_simple_grp_chk_discrim

/* Hack som long STORE names */
#undef STORE_method_set_initialise_function
#define STORE_method_set_initialise_function STORE_meth_set_initialise_fn
#undef STORE_method_set_cleanup_function
#define STORE_method_set_cleanup_function STORE_meth_set_cleanup_fn
#undef STORE_method_set_generate_function
#define STORE_method_set_generate_function STORE_meth_set_generate_fn
#undef STORE_method_set_modify_function
#define STORE_method_set_modify_function STORE_meth_set_modify_fn
#undef STORE_method_set_revoke_function
#define STORE_method_set_revoke_function STORE_meth_set_revoke_fn
#undef STORE_method_set_delete_function
#define STORE_method_set_delete_function STORE_meth_set_delete_fn
#undef STORE_method_set_list_start_function
#define STORE_method_set_list_start_function STORE_meth_set_list_start_fn
#undef STORE_method_set_list_next_function
#define STORE_method_set_list_next_function STORE_meth_set_list_next_fn
#undef STORE_method_set_list_end_function
#define STORE_method_set_list_end_function STORE_meth_set_list_end_fn
#undef STORE_method_set_update_store_function
#define STORE_method_set_update_store_function STORE_meth_set_update_store_fn
#undef STORE_method_set_lock_store_function
#define STORE_method_set_lock_store_function STORE_meth_set_lock_store_fn
#undef STORE_method_set_unlock_store_function
#define STORE_method_set_unlock_store_function STORE_meth_set_unlock_store_fn
#undef STORE_method_get_initialise_function
#define STORE_method_get_initialise_function STORE_meth_get_initialise_fn
#undef STORE_method_get_cleanup_function
#define STORE_method_get_cleanup_function STORE_meth_get_cleanup_fn
#undef STORE_method_get_generate_function
#define STORE_method_get_generate_function STORE_meth_get_generate_fn
#undef STORE_method_get_modify_function
#define STORE_method_get_modify_function STORE_meth_get_modify_fn
#undef STORE_method_get_revoke_function
#define STORE_method_get_revoke_function STORE_meth_get_revoke_fn
#undef STORE_method_get_delete_function
#define STORE_method_get_delete_function STORE_meth_get_delete_fn
#undef STORE_method_get_list_start_function
#define STORE_method_get_list_start_function STORE_meth_get_list_start_fn
#undef STORE_method_get_list_next_function
#define STORE_method_get_list_next_function STORE_meth_get_list_next_fn
#undef STORE_method_get_list_end_function
#define STORE_method_get_list_end_function STORE_meth_get_list_end_fn
#undef STORE_method_get_update_store_function
#define STORE_method_get_update_store_function STORE_meth_get_update_store_fn
#undef STORE_method_get_lock_store_function
#define STORE_method_get_lock_store_function STORE_meth_get_lock_store_fn
#undef STORE_method_get_unlock_store_function
#define STORE_method_get_unlock_store_function STORE_meth_get_unlock_store_fn

#endif /* defined OPENSSL_SYS_VMS */

/* Case insensiteve linking causes problems.... */
#if defined(OPENSSL_SYS_WIN16) || defined(OPENSSL_SYS_VMS) || \
    defined(OPENSSL_SYS_OS2)
#undef ERR_load_CRYPTO_strings
#define ERR_load_CRYPTO_strings ERR_load_CRYPTOlib_strings
#undef OCSP_crlID_new
#define OCSP_crlID_new OCSP_crlID2_new

#undef d2i_ECPARAMETERS
#define d2i_ECPARAMETERS d2i_UC_ECPARAMETERS
#undef i2d_ECPARAMETERS
#define i2d_ECPARAMETERS i2d_UC_ECPARAMETERS
#undef d2i_ECPKPARAMETERS
#define d2i_ECPKPARAMETERS d2i_UC_ECPKPARAMETERS
#undef i2d_ECPKPARAMETERS
#define i2d_ECPKPARAMETERS i2d_UC_ECPKPARAMETERS

/* These functions do not seem to exist!  However, I'm paranoid...
   Original command in x509v3.h:
   These functions are being redefined in another directory,
   and clash when the linker is case-insensitive, so let's
   hide them a little, by giving them an extra 'o' at the
   beginning of the name... */
#undef X509v3_cleanup_extensions
#define X509v3_cleanup_extensions oX509v3_cleanup_extensions
#undef X509v3_add_extension
#define X509v3_add_extension oX509v3_add_extension
#undef X509v3_add_netscape_extensions
#define X509v3_add_netscape_extensions oX509v3_add_netscape_extensions
#undef X509v3_add_standard_extensions
#define X509v3_add_standard_extensions oX509v3_add_standard_extensions

#endif

#endif /* ! defined HEADER_VMS_IDHACKS_H */
