//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <math/Vec.h>
#include <edit/Generated/Forward.h>
#include <edit/Tool.h>

#include <vector>

namespace mud
{
	class _refl_ MUD_EDIT_EXPORT RotateAction : public TransformAction
	{
	public:
		RotateAction(const std::vector<Transform*>& targets, const vec3& axis);

		virtual void apply(Transform& transform) final;
		virtual void undo(Transform& transform) final;

		virtual void update(const vec3& start, const vec3& end);

	private:
		vec3 m_axis;
		float m_angle;
	};

	class _refl_ MUD_EDIT_EXPORT RotateTool : public TransformTool
	{
	public:
		RotateTool(ToolContext& context);

		Gizmo rotation_gizmo(Axis axis, vec3 dir, vec3 p1, vec3 p2, Colour colour);

		virtual object_ptr<TransformAction> create_action(const std::vector<Transform*>& transforms);
	};
}
