#include "QuadCommand.h"
#include "DirectXUtils.h"

QuadCommand::QuadCommand()
	:enable(false), zOrder(0)
{
	this->autorelease();
}

QuadCommand::QuadCommand(const QuadCommand& copy_obj)
	:render_texture(copy_obj.render_texture), render_rect(copy_obj.render_rect),
	anchorPoint(copy_obj.anchorPoint), final_matrix(copy_obj.final_matrix),
	enable(copy_obj.enable), zOrder(copy_obj.zOrder)
{}

void QuadCommand::render() const
{
	_directUtils->drawImage(render_texture, render_rect, anchorPoint, final_matrix);
}
