#if defined(__GNUC__)
	#include <features.h>
	#if !(__GLIBC_PREREQ(2,28)) && defined(_SYS_SYSMACROS_H)
		// Because of a bug in GLIBC<2.28 where <sys/sysmacros.h> is being
		// included in <sys/types.h>, the macros `major` and `minor` are
		// defined which interfere. Fore more information, see
		//
		// - https://gcc.gnu.org/bugzilla/show_bug.cgi?id=51749
		// - https://sourceware.org/bugzilla/show_bug.cgi?format=multiple&id=19239
		// - https://bugzilla.redhat.com/show_bug.cgi?id=130601

		#if defined(major)
			#undef major
		#endif
		#if defined(minor)
			#undef minor
		#endif
	#endif
#endif

