/*
    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/
/**
 * \file nanoui/layout.h
 *
 * \brief A collection of useful layout managers.  The \ref nanoui::GridLayout
 *        was contributed by Christian Schueller.
 */

#pragma once

#include <nanoui/object.h>
#include <nanoui/vector.h>
#include <unordered_map>
#include <vector>

namespace nanoui
{

/// The different kinds of alignments a layout can perform.
enum enum_alignment : uint8_t {
   e_alignment_minimum = 0, ///< Take only as much space as is required.
   e_alignment_middle,      ///< Center align.
   e_alignment_maximum,     ///< Take as much space as is allowed.
   e_alignment_fill         ///< Fill according to preferred sizes.
};

/// The direction of data flow for a layout.
enum class enum_orientation {
   e_orientation_horizontal = 0, ///< Layout expands on horizontal axis.
   e_orientation_vertical        ///< Layout expands on vertical axis.
};

/**
 * \class Layout layout.h nanoui/layout.h
 *
 * \brief Basic interface of a layout engine.
 */
class NANOUI_EXPORT Layout : public Object {
public:
   /**
    * Performs applies all layout computations for the given widget.
    *
    * \param ctx
    *     The ``NanoVG`` context being used for drawing.
    *
    * \param widget
    *     The Widget whose child widgets will be positioned by the layout class..
    */
   //virtual void perform_layout(NVGcontext * ctx, Widget * widget) const = 0;

   /**
    * Compute the preferred size for a given layout and widget
    *
    * \param ctx
    *     The ``NanoVG`` context being used for drawing.
    *
    * \param widget
    *     Widget, whose preferred size should be computed
    *
    * \return
    *     The preferred size, accounting for things such as spacing, padding
    *     for icons, etc.
    */
   // virtual Vector2i preferred_size(NVGcontext * ctx, const Widget * widget) const = 0;
protected:
   /// Default destructor (exists for inheritance).
   virtual ~Layout() { }
};

/**
 * \class BoxLayout layout.h nanoui/layout.h
 *
 * \brief Simple horizontal/vertical box layout
 *
 * This widget stacks up a bunch of widgets horizontally or vertically. It adds
 * margins around the entire container and a custom spacing between adjacent
 * widgets.
 */
class NANOUI_EXPORT BoxLayout : public Layout {
public:
   /**
    * \brief Construct a box layout which packs widgets in the given \c enum_orientation
    *
    * \param orientation
    *     The enum_orientation this BoxLayout expands along
    *
    * \param alignment
    *     Widget alignment perpendicular to the chosen orientation
    *
    * \param margin
    *     Margin around the layout container
    *
    * \param spacing
    *     Extra spacing placed between widgets
    */
   BoxLayout(enum_orientation orientation, enum_alignment alignment = e_alignment_middle,
      int margin = 0, int spacing = 0);

   /// The enum_orientation this BoxLayout is using.
   enum_orientation orientation() const { return m_orientation; }

   /// Sets the enum_orientation of this BoxLayout.
   void set_orientation(enum_orientation orientation) { m_orientation = orientation; }

   /// The enum_alignment of this BoxLayout.
   enum_alignment alignment() const { return m_alignment; }

   /// Sets the enum_alignment of this BoxLayout.
   void set_alignment(enum_alignment alignment) { m_alignment = alignment; }

   /// The margin of this BoxLayout.
   int margin() const { return m_margin; }

   /// Sets the margin of this BoxLayout.
   void set_margin(int margin) { m_margin = margin; }

   /// The spacing this BoxLayout is using to pad in between widgets.
   int spacing() const { return m_spacing; }

   /// Sets the spacing of this BoxLayout.
   void set_spacing(int spacing) { m_spacing = spacing; }

   /* Implementation of the layout interface */

   /// See \ref Layout::preferred_size.
   //virtual Vector2i preferred_size(NVGcontext * ctx, const Widget * widget) const override;

   /// See \ref Layout::perform_layout.
   //virtual void perform_layout(NVGcontext * ctx, Widget * widget) const override;

protected:
   /// The enum_orientation of this BoxLayout.
   enum_orientation m_orientation;

   /// The enum_alignment of this BoxLayout.
   enum_alignment m_alignment;

   /// The margin padding of this BoxLayout.
   int m_margin;

   /// The spacing between widgets of this BoxLayout.
   int m_spacing;
};

/**
 * \class GroupLayout layout.h nanoui/layout.h
 *
 * \brief Special layout for widgets grouped by labels.
 *
 * This widget resembles a box layout in that it arranges a set of widgets
 * vertically. All widgets are indented on the horizontal axis except for
 * \ref Label widgets, which are not indented.
 *
 * This creates a pleasing layout where a number of widgets are grouped
 * under some high-level heading.
 */
class NANOUI_EXPORT GroupLayout : public Layout {
public:
   /**
    * Creates a GroupLayout.
    *
    * \param margin
    *     The margin around the widgets added.
    *
    * \param spacing
    *     The spacing between widgets added.
    *
    * \param group_spacing
    *     The spacing between groups (groups are defined by each Label added).
    *
    * \param group_indent
    *     The amount to indent widgets in a group (underneath a Label).
    */
   GroupLayout(int margin = 15, int spacing = 6, int group_spacing = 14,
      int group_indent = 20)
      : m_margin(margin), m_spacing(spacing), m_group_spacing(group_spacing),
      m_group_indent(group_indent) {}

   /// The margin of this GroupLayout.
   int margin() const { return m_margin; }

   /// Sets the margin of this GroupLayout.
   void set_margin(int margin) { m_margin = margin; }

   /// The spacing between widgets of this GroupLayout.
   int spacing() const { return m_spacing; }

   /// Sets the spacing between widgets of this GroupLayout.
   void set_spacing(int spacing) { m_spacing = spacing; }

   /// The indent of widgets in a group (underneath a Label) of this GroupLayout.
   int group_indent() const { return m_group_indent; }

   /// Sets the indent of widgets in a group (underneath a Label) of this GroupLayout.
   void set_group_indent(int group_indent) { m_group_indent = group_indent; }

   /// The spacing between groups of this GroupLayout.
   int group_spacing() const { return m_group_spacing; }

   /// Sets the spacing between groups of this GroupLayout.
   void set_group_spacing(int group_spacing) { m_group_spacing = group_spacing; }

   /* Implementation of the layout interface */

   /// See \ref Layout::preferred_size.
   //virtual Vector2i preferred_size(NVGcontext * ctx, const Widget * widget) const override;

   /// See \ref Layout::perform_layout.
   //virtual void perform_layout(NVGcontext * ctx, Widget * widget) const override;

protected:
   /// The margin of this GroupLayout.
   int m_margin;

   /// The spacing between widgets of this GroupLayout.
   int m_spacing;

   /// The spacing between groups of this GroupLayout.
   int m_group_spacing;

   /// The indent amount of a group under its defining Label of this GroupLayout.
   int m_group_indent;
};

/**
 * \class GridLayout layout.h nanoui/layout.h
 *
 * \brief Grid layout.
 *
 * Widgets are arranged in a grid that has a fixed grid resolution \c resolution
 * along one of the axes. The layout orientation indicates the fixed dimension;
 * widgets are also appended on this axis. The spacing between items can be
 * specified per axis. The horizontal/vertical alignment can be specified per
 * row and column.
 */
class NANOUI_EXPORT GridLayout : public Layout {
public:
   /**
    * Create a 2-column grid layout by default.
    *
    * \param orientation
    *     The fixed dimension of this GridLayout.
    *
    * \param resolution
    *     The number of rows or columns in the grid (depending on the enum_orientation).
    *
    * \param alignment
    *     How widgets should be aligned within each grid cell.
    *
    * \param margin
    *     The amount of spacing to add around the border of the grid.
    *
    * \param spacing
    *     The amount of spacing between widgets added to the grid.
    */
   GridLayout(enum_orientation orientation = e_orientation_horizontal, int resolution = 2,
      enum_alignment alignment = e_alignment_middle,
      int margin = 0, int spacing = 0)
      : m_orientation(orientation), m_resolution(resolution), m_margin(margin) {
      m_default_alignment[0] = m_default_alignment[1] = alignment;
      m_spacing = Vector2i(spacing);
   }

   /// The enum_orientation of this GridLayout.
   enum_orientation orientation() const { return m_orientation; }

   /// Sets the enum_orientation of this GridLayout.
   void set_orientation(enum_orientation orientation) {
      m_orientation = orientation;
   }

   /// The number of rows or columns (depending on the enum_orientation) of this GridLayout.
   int resolution() const { return m_resolution; }
   /// Sets the number of rows or columns (depending on the enum_orientation) of this GridLayout.
   void set_resolution(int resolution) { m_resolution = resolution; }

   /// The spacing at the specified axis (row or column number, depending on the enum_orientation).
   int spacing(int axis) const { return m_spacing[axis]; }
   /// Sets the spacing for a specific axis.
   void set_spacing(int axis, int spacing) { m_spacing[axis] = spacing; }
   /// Sets the spacing for all axes.
   void set_spacing(int spacing) { m_spacing[0] = m_spacing[1] = spacing; }

   /// The margin around this GridLayout.
   int margin() const { return m_margin; }
   /// Sets the margin of this GridLayout.
   void set_margin(int margin) { m_margin = margin; }

   /**
    * The enum_alignment of the specified axis (row or column number, depending on
    * the enum_orientation) at the specified index of that row or column.
    */
   enum_alignment alignment(int axis, int item) const {
      if (item < (int)m_alignment[axis].size())
         return m_alignment[axis][item];
      else
         return m_default_alignment[axis];
   }

   /// Sets the enum_alignment of the columns.
   void set_col_alignment(enum_alignment value) { m_default_alignment[0] = value; }

   /// Sets the enum_alignment of the rows.
   void set_row_alignment(enum_alignment value) { m_default_alignment[1] = value; }

   /// Use this to set variable enum_alignment for columns.
   void set_col_alignment(const std::vector<enum_alignment> & value) { m_alignment[0] = value; }

   /// Use this to set variable enum_alignment for rows.
   void set_row_alignment(const std::vector<enum_alignment> & value) { m_alignment[1] = value; }

   /* Implementation of the layout interface */
   /// See \ref Layout::preferred_size.
   //virtual Vector2i preferred_size(NVGcontext * ctx, const Widget * widget) const override;

   /// See \ref Layout::perform_layout.
   //virtual void perform_layout(NVGcontext * ctx, Widget * widget) const override;

protected:
   // Compute the maximum row and column sizes
   //void compute_layout(NVGcontext * ctx, const Widget * widget,
      //std::vector<int> * grid) const;

protected:
   /// The enum_orientation of the GridLayout.
   enum_orientation m_orientation;
   /// The default enum_alignment of the GridLayout.
   enum_alignment m_default_alignment[2];
   /// The actual enum_alignment being used for each column/row
   std::vector<enum_alignment> m_alignment[2];
   /// The number of rows or columns before starting a ___new one, depending on the enum_orientation.
   int m_resolution;
   /// The spacing used for each dimension.
   Vector2i m_spacing;
   /// The margin around this GridLayout.
   int m_margin;
};

/**
 * \class AdvancedGridLayout layout.h nanoui/layout.h
 *
 * \brief Advanced Grid layout.
 *
 * The is a fancier grid layout with support for items that span multiple rows
 * or columns, and per-widget alignment flags. Each row and column additionally
 * stores a stretch factor that controls how additional space is redistributed.
 * The downside of this flexibility is that a layout anchor data structure must
 * be provided for each widget.
 *
 * An example:
 *
 * \rst
 * .. code-block:: cpp
 *
 *    using Anchor = AdvancedGridLayout::Anchor;
 *    Label *label = ___new Label(window, "A label");
 *    // Add a centered label at grid position (1, 5), which spans two horizontal cells
 *    layout->set_anchor(label, Anchor(1, 5, 2, 1, e_alignment_middle, e_alignment_middle));
 *
 * \endrst
 *
 * The grid is initialized with user-specified column and row size vectors
 * (which can be expanded later on if desired). If a size value of zero is
 * specified for a column or row, the size is set to the maximum preferred size
 * of any widgets contained in the same row or column. Any remaining space is
 * redistributed according to the row and column stretch factors.
 *
 * The high level usage somewhat resembles the classic HIG layout:
 *
 * - https://web.archive.org/web/20070813221705/http://www.autel.cz/dmi/tutorial.html
 * - https://github.com/jaapgeurts/higlayout
 */
class NANOUI_EXPORT AdvancedGridLayout : public Layout {
public:
   /**
    * \struct Anchor layout.h nanoui/layout.h
    *
    * \brief Helper struct to coordinate anchor points for the layout.
    */
   struct Anchor {
      uint8_t pos[2];    ///< The ``(x, y)`` position.
      uint8_t size[2];   ///< The ``(x, y)`` size.
      enum_alignment align[2];///< The ``(x, y)`` enum_alignment.

      /// Creates a ``0`` Anchor.
      Anchor() { }

      /// Create an Anchor at position ``(x, y)`` with specified enum_alignment.
      Anchor(int x, int y, enum_alignment horiz = e_alignment_fill,
         enum_alignment vert = e_alignment_fill) {
         pos[0] = (uint8_t)x; pos[1] = (uint8_t)y;
         size[0] = size[1] = 1;
         align[0] = horiz; align[1] = vert;
      }

      /// Create an Anchor at position ``(x, y)`` of size ``(w, h)`` with specified alignments.
      Anchor(int x, int y, int w, int h,
         enum_alignment horiz = e_alignment_fill,
         enum_alignment vert = e_alignment_fill) {
         pos[0] = (uint8_t)x; pos[1] = (uint8_t)y;
         size[0] = (uint8_t)w; size[1] = (uint8_t)h;
         align[0] = horiz; align[1] = vert;
      }

      /// Allows for printing out Anchor position, size, and alignment.
      operator std::string() const {
         char buf[50];
         std::snprintf(buf, 50, "Format[pos=(%i, %i), size=(%i, %i), align=(%i, %i)]",
            pos[0], pos[1], size[0], size[1], (int)align[0], (int)align[1]);
         return buf;
      }
   };

   /// Creates an AdvancedGridLayout with specified columns, rows, and margin.
   AdvancedGridLayout(const std::vector<int> & cols = {}, const std::vector<int> & rows = {}, int margin = 0);

   /// The margin of this AdvancedGridLayout.
   int margin() const { return m_margin; }
   /// Sets the margin of this AdvancedGridLayout.
   void set_margin(int margin) { m_margin = margin; }

   /// Return the number of cols
   int col_count() const { return (int)m_cols.size(); }

   /// Return the number of rows
   int row_count() const { return (int)m_rows.size(); }

   /// Append a row of the given size (and stretch factor)
   void append_row(int size, float stretch = 0.f) { m_rows.push_back(size); m_row_stretch.push_back(stretch); };

   /// Append a column of the given size (and stretch factor)
   void append_col(int size, float stretch = 0.f) { m_cols.push_back(size); m_col_stretch.push_back(stretch); };

   /// Set the stretch factor of a given row
   void set_row_stretch(int index, float stretch) { m_row_stretch.at(index) = stretch; }

   /// Set the stretch factor of a given column
   void set_col_stretch(int index, float stretch) { m_col_stretch.at(index) = stretch; }

   /// Specify the anchor data structure for a given widget
   void set_anchor(const Widget * widget, const Anchor & anchor) { m_anchor[widget] = anchor; }

   /// Retrieve the anchor data structure for a given widget
   Anchor anchor(const Widget * widget) const {
      auto it = m_anchor.find(widget);
      if (it == m_anchor.end())
         throw std::runtime_error("Widget was not registered with the grid layout!");
      return it->second;
   }

   /* Implementation of the layout interface */

   /// See \ref Layout::preferred_size.
   //virtual Vector2i preferred_size(NVGcontext * ctx, const Widget * widget) const override;

   /// See \ref Layout::perform_layout.
   //virtual void perform_layout(NVGcontext * ctx, Widget * widget) const override;

protected:
   // Compute the maximum row and column sizes
   //void compute_layout(NVGcontext * ctx, const Widget * widget,
     // std::vector<int> * grid) const;

protected:
   /// The columns of this AdvancedGridLayout.
   std::vector<int> m_cols;

   /// The rows of this AdvancedGridLayout.
   std::vector<int> m_rows;

   /// The stretch for each column of this AdvancedGridLayout.
   std::vector<float> m_col_stretch;

   /// The stretch for each row of this AdvancedGridLayout.
   std::vector<float> m_row_stretch;

   /// The mapping of widgets to their specified anchor points.
   std::unordered_map<const Widget *, Anchor> m_anchor;

   /// The margin around this AdvancedGridLayout.
   int m_margin;
};


} // namespace nanoui



