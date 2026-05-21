version,4.000
date,"2026/01/14 14:14:53"
begingroup,AREANCONDRC
  begingroup,AREANCONDRC_RESIST
    case,AREANCONDRC_RESMISS,"2026/01/14 14:14",2025.200
    case,AREANCONDRC_RESRES,"2026/01/14 14:14",2025.200
    case,AREANCONDRC_RESBRD,"2026/01/14 14:14",2025.200
    case,AREANCONDRC_RESANNU,"2026/01/14 14:14",2025.200
  endgroup
  begingroup,AREANCONDRC_SYMBOLMARK
    begingroup,AREANCONDRC_SYMSYM
      case,AREANCONDRC_SYMSYM_STR,"2026/01/14 14:14",2025.200
      case,AREANCONDRC_SYMSYM_TYP,"2026/01/14 14:14",2025.200
      case,AREANCONDRC_SYMSYM_NON,"2026/01/14 14:14",2025.200
      case,AREANCONDRC_SYMSYM_DUP,"2026/01/14 14:14",2025.200
      case,AREANCONDRC_SYMSYM_DES,"2026/01/14 14:14",2025.200
      case,AREANCONDRC_SYMSYM_CRS,"2026/01/14 14:14",2025.200
      case,AREANCONDRC_SYMSYM_CRSREL,"2026/01/14 14:14",2025.200
    endgroup
  endgroup
  begingroup,AREANCONDRC_METALMASK
    case,AREANCONDRC_SLDMISS,"2026/01/14 14:14",2025.200
      result,E,"","",,
        param,"padstk","MIS1","N:MetalMask-A"
        distParams,0,0
        intParams,14
        stringParams,"MIS1"
        zoomarea,0,10095000,975000,11225000,2225000
        color,0,255,255
        linewidthmode,VDC
        filltype,none,0,0
          figure,box,"10595000","1475000","10725000","1725000"
          figure,text,"DRC[M Miss]","10660000","1600000","12063","12063","0","0","0","raster"
        color,-1,-1,-1
        linewidthmode,VDC
        filltype,none,0,0
          layer,cond,"1",""
          layer,ncond,"MetalMask-A",""
            primitive,padstkref,N,,"RCT_1m3_2m5NP","10660000","1600000","0","0"
          keyobj,"comp",,"MIS1"
      result,E,"","",,
        param,"padstk","MIS2","N:MetalMask-A"
        distParams,0,0
        intParams,14
        stringParams,"MIS2"
        zoomarea,0,10095000,2825000,11225000,4075000
        color,0,255,255
        linewidthmode,VDC
        filltype,none,0,0
          figure,box,"10595000","3325000","10725000","3575000"
          figure,text,"DRC[M Miss]","10660000","3450000","12063","12063","0","0","0","raster"
        color,-1,-1,-1
        linewidthmode,VDC
        filltype,none,0,0
          layer,cond,"1",""
          layer,ncond,"MetalMask-A",""
            primitive,padstkref,N,,"RCT_1m3_2m5NP","10660000","3450000","0","0"
          keyobj,"comp",,"MIS2"
    case,AREANCONDRC_SLDSLD,"2026/01/14 14:14",2025.200
  endgroup
  begingroup,AREANCONDRC_HOLE
    begingroup,AAREANCONDRC_DRLDRL
      case,AREANCONDRC_DRLDRL_DUPLI,"2026/01/14 14:14",2025.200
      case,AREANCONDRC_DRLDRL_TOUCH,"2026/01/14 14:14",2025.200
      case,AREANCONDRC_DRLDRL_CLEAR,"2026/01/14 14:14",2025.200
    endgroup
    case,AREANCONDRC_DRLBRD,"2026/01/14 14:14",2025.200
  endgroup
endgroup
