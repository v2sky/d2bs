#include "ScreenHooks.h"

/** This class represents a screen hook for a Image.
 *
 * \todo Explain (and understand) this better.
 * \todo Verify all the documentation in this class.
 */
class Image
{
public:
	/** Create an Image hook with the given parameters.
	 *
	 * \param szText The filename to load the image from.
	 *
	 * \param x The x coordinate (left) of the Image.
	 *
	 * \param y The y coordinate (top) of the Image.
	 *
	 * \param color See \ref sh_color
	 *
	 * See: http://forums.d2botnet.org/viewtopic.php?f=18&t=1000
	 *
	 * \param align The horizontal alignment.
	 *
	 * 0 - Left
	 *
	 * 1 - Right
	 *
	 * 2 - Center
	 *
	 * \param automap Whether the Image is in automap coordinate space (true) or
	 * screen coordinate space (false).
	 *
	 * \param click The click handler that gets called when the Image is
	 * clicked.
	 *
	 * \param hover The hover handler that gets called when the Image gets
	 * hovered over.
	 */
	Image(String szText = "", int x = 0, int y = 0, int color = 0,
		int align = 0, bool automap = false, ClickHandler click = null,
		HoverHandler hover = null);

	/** Remove the Image from the screen and destroy the corresponding object.
	 */
	void remove();

	/** The x coordinate (left) of the Image.
	 */
	int x;

	/** The y coordinate (top) of the Image.
	 */
	int y;

	/** Whether or not the Image is visible.
	 */
	bool visible;

	/** The horizontal alignment.
	 *
	 * 0 - Left
	 *
	 * 1 - Right
	 *
	 * 2 - Center
	 */
	int align;

	/** The z-order of the Image (what it covers up and is covered by).
	 */
	int zorder;

	/** The click handler that gets called when the Image is clicked.
	 */
	ClickHandler click;

	/** The hover handler that gets called when the Image gets hovered over.
	 */
	HoverHandler hover;

	/** Location of the file to load for display.
	 */
	String location;
};
