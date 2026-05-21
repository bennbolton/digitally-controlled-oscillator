version,4.000
date,"2026/01/14 14:14:53"
begingroup,AREADRC
  begingroup,AREADRC_CLEARANCE
    begingroup,AREADRC_CLEARANCE_NORMAL
      case,AREADRC_CLEARANCE_NORMAL_CLEARANCE,"2026/01/14 14:14",2025.200
      case,AREADRC_CLEARANCE_NORMAL_SHORT,"2026/01/14 14:14",2025.200
      case,AREADRC_CLEARANCE_NORMAL_INHIBIT,"2026/01/14 14:14",2025.200
      case,AREADRC_CLEARANCE_NORMAL_HOLE,"2026/01/14 14:14",2025.200
      case,AREADRC_CLEARANCE_NORMAL_PIN,"2026/01/14 14:14",2025.200
      case,AREADRC_CLEARANCE_NORMAL_OPEN,"2026/01/14 14:14",2025.200
    endgroup
    begingroup,AREADRC_CLEARANCE_INCOMP
      case,AREADRC_CLEARANCE_INCOMP_CLEARANCE,"2026/01/14 14:14",2025.200
      case,AREADRC_CLEARANCE_INCOMP_SHORT,"2026/01/14 14:14",2025.200
    endgroup
    begingroup,AREADRC_CLEARANCE_VIAHOLE
      case,AREADRC_CLEARANCE_VIAHOLE_CLEARANCE,"2026/01/14 14:14",2025.200
      case,AREADRC_CLEARANCE_VIAHOLE_SHORT,"2026/01/14 14:14",2025.200
    endgroup
  endgroup
  begingroup,AREADRC_SAMENET
    begingroup,AREADRC_SAMENET_CLEARANCE
      case,AREADRC_SAMENET_CLEARANCE_CLEARANCE,"2026/01/14 14:14",2025.200
      case,AREADRC_SAMENET_CLEARANCE_SHORT,"2026/01/14 14:14",2025.200
    endgroup
    case,AREADRC_SAMENET_OVERLAPVIA,"2026/01/14 14:14",2025.200
    case,AREADRC_SAMENET_OVERLAPPATTERN,"2026/01/14 14:14",2025.200
      result,E,"","",,
        param,"C:2","surf","surf","GND","GND"
        zoomarea,0,2290500,1652500,3325500,2687500
        color,0,255,255
        linewidthmode,VDC
        filltype,none,0,0
          figure,box,"2740500","2102500","2875500","2237500"
          figure,text,"DRC[2:same-pattern]","2808000","2170000","12063","12063","0","0","0","raster"
        color,-1,-1,-1
        linewidthmode,VDC
        filltype,none,0,0
          layer,cond,"2",""
            primitive,surf,N,,"2740500","2102500","2875500","2237500"
            primitive,surf,N,,"2740500","2102500","2875500","2237500"
          keyobj,"net",,"GND"
          keyobj,"enet",,"GND"
      result,E,"","",,
        param,"C:2","surf","surf","GND","GND"
        zoomarea,0,2544500,2414500,3579500,3449500
        color,0,255,255
        linewidthmode,VDC
        filltype,none,0,0
          figure,box,"2994500","2864500","3129500","2999500"
          figure,text,"DRC[2:same-pattern]","3062000","2932000","12063","12063","0","0","0","raster"
        color,-1,-1,-1
        linewidthmode,VDC
        filltype,none,0,0
          layer,cond,"2",""
            primitive,surf,N,,"2994500","2864500","3129500","2999500"
            primitive,surf,N,,"2994500","2864500","3129500","2999500"
          keyobj,"net",,"GND"
          keyobj,"enet",,"GND"
      result,E,"","",,
        param,"C:2","surf","surf","GND","GND"
        zoomarea,0,4120500,2414500,5155500,3449500
        color,0,255,255
        linewidthmode,VDC
        filltype,none,0,0
          figure,box,"4570500","2864500","4705500","2999500"
          figure,text,"DRC[2:same-pattern]","4638000","2932000","12063","12063","0","0","0","raster"
        color,-1,-1,-1
        linewidthmode,VDC
        filltype,none,0,0
          layer,cond,"2",""
            primitive,surf,N,,"4570500","2864500","4705500","2999500"
            primitive,surf,N,,"4570500","2864500","4705500","2999500"
          keyobj,"net",,"GND"
          keyobj,"enet",,"GND"
      result,E,"","",,
        param,"C:2","surf","surf","GND","GND"
        zoomarea,0,6214500,2414500,7249500,3449500
        color,0,255,255
        linewidthmode,VDC
        filltype,none,0,0
          figure,box,"6664500","2864500","6799500","2999500"
          figure,text,"DRC[2:same-pattern]","6732000","2932000","12063","12063","0","0","0","raster"
        color,-1,-1,-1
        linewidthmode,VDC
        filltype,none,0,0
          layer,cond,"2",""
            primitive,surf,N,,"6664500","2864500","6799500","2999500"
            primitive,surf,N,,"6664500","2864500","6799500","2999500"
          keyobj,"net",,"GND"
          keyobj,"enet",,"GND"
      result,E,"","",,
        param,"C:2","surf","surf","GND","GND"
        zoomarea,0,8064500,2414500,9099500,3449500
        color,0,255,255
        linewidthmode,VDC
        filltype,none,0,0
          figure,box,"8514500","2864500","8649500","2999500"
          figure,text,"DRC[2:same-pattern]","8582000","2932000","12063","12063","0","0","0","raster"
        color,-1,-1,-1
        linewidthmode,VDC
        filltype,none,0,0
          layer,cond,"2",""
            primitive,surf,N,,"8514500","2864500","8649500","2999500"
            primitive,surf,N,,"8514500","2864500","8649500","2999500"
          keyobj,"net",,"GND"
          keyobj,"enet",,"GND"
  endgroup
  begingroup,AREADRC_BADCONNECT
    begingroup,AREADRC_BADCONNECT_OPENSURF
      case,AREADRC_BADCONNECT_OPENSURF_COMPTERM,"2026/01/14 14:14",2025.200
      case,AREADRC_BADCONNECT_OPENSURF_OTHER,"2026/01/14 14:14",2025.200
      case,AREADRC_BADCONNECT_OPENSURF_WINDOW,"2026/01/14 14:14",2025.200
      case,AREADRC_BADCONNECT_OPENSURF_OPENSURF,"2026/01/14 14:14",2025.200
    endgroup
    case,AREADRC_BADCONNECT_UNCONNECTTHERMAL,"2026/01/14 14:14",2025.200
    case,AREADRC_BADCONNECT_COLLAPSETHERMAL,"2026/01/14 14:14",2025.200
    case,AREADRC_BADCONNECT_UNCONNECT,"2026/01/14 14:14",2025.200
  endgroup
  begingroup,AREADRC_BRDSPEC
    begingroup,AREADRC_BRDSPEC_INTERSTICIAL
      case,AREADRC_BRDSPEC_INTERSTICIAL_FROMTO,"2026/01/14 14:14",2025.200
      case,AREADRC_BRDSPEC_INTERSTICIAL_QUALIFIEDPADSTK,"2026/01/14 14:14",2025.200
    endgroup
    case,AREADRC_BRDSPEC_MINLANDOVERLAP,"2026/01/14 14:14",2025.200
  endgroup
  begingroup,AREADRC_SPVIA
    case,AREADRC_SPVIA_ANTENNA,"2026/01/14 14:14",2025.200
  endgroup
  begingroup,AREADRC_OTHER
    begingroup,AREADRC_RESIST
      case,AREADRC_RESIST_CLEARANCE,"2026/01/14 14:14",2025.200
      case,AREADRC_RESIST_SHORT,"2026/01/14 14:14",2025.200
    endgroup
    begingroup,AREADRC_WIRWID
      case,AREADRC_WIRWID_MAX,"2026/01/14 14:14",2025.200
      case,AREADRC_WIRWID_MIN,"2026/01/14 14:14",2025.200
      case,AREADRC_WIRWID_LIMIT,"2026/01/14 14:14",2025.200
    endgroup
    begingroup,AREADRC_SHAPEINPADSTK
      case,AREADRC_SHAPEINPADSTK_LANDSTATUS,"2026/01/14 14:14",2025.200
      case,AREADRC_SHAPEINPADSTK_CONNECT,"2026/01/14 14:14",2025.200
      case,AREADRC_SHAPEINPADSTK_NOCONNECT,"2026/01/14 14:14",2025.200
      case,AREADRC_SHAPEINPADSTK_THERMAL,"2026/01/14 14:14",2025.200
      case,AREADRC_SHAPEINPADSTK_CLEARANCE,"2026/01/14 14:14",2025.200
    endgroup
    case,AREADRC_ANTENNA_LINE,"2026/01/14 14:14",2025.200
  endgroup
endgroup
